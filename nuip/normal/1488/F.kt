import java.io.PrintWriter
import java.util.*

@JvmField val INPUT = System.`in`
//@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readStrings(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readInts(n: Int) = List(n) { read().toInt() }
fun readIntArray(n: Int) = IntArray(n) { read().toInt() }
fun readDoubles(n: Int) = List(n) { read().toDouble() }
fun readDoubleArray(n: Int) = DoubleArray(n) { read().toDouble() }
fun readLongs(n: Int) = List(n) { read().toLong() }
fun readLongArray(n: Int) = LongArray(n) { read().toLong() }

class LazySegTree<S, F>(
    private val MAX: Int,
    op: (S, S) -> S,
    e: S,
    mapping: (F, S) -> S,
    composition: (F, F) -> F,
    id: F
) {
    private val n: Int
    private val log: Int
    private val op: (S, S) -> S
    private val e: S
    private val mapping: (F, S) -> S
    private val composition: (F, F) -> F
    private val id: F
    private val dat: Array<S>
    private val laz: Array<F>

    constructor(
        dat: Array<S>,
        op: (S, S) -> S,
        e: S,
        mapping: (F, S) -> S,
        composition: (F, F) -> F,
        id: F
    ) : this(dat.size, op, e, mapping, composition, id) {
        build(dat)
    }

    init {
        var k = 1
        while (k < MAX) k = k shl 1
        n = k
        log = Integer.numberOfTrailingZeros(n)
        this.op = op
        this.e = e
        this.mapping = mapping
        this.composition = composition
        this.id = id
        @Suppress("UNCHECKED_CAST")
        dat = Array(n shl 1) { e as Any } as Array<S>
        @Suppress("UNCHECKED_CAST")
        laz = Array(n) { id as Any } as Array<F>
        Arrays.fill(dat, this.e)
        Arrays.fill(laz, this.id)
    }

    private fun build(dat: Array<S>) {
        val l = dat.size
        System.arraycopy(dat, 0, this.dat, n, l)
        for (i in n - 1 downTo 1) {
            this.dat[i] = op(this.dat[i shl 1], this.dat[i shl 1 or 1])
        }
    }

    private fun push(k: Int) {
        if (laz[k] === id) return
        val lk = k shl 1
        val rk = k shl 1 or 1
        dat[lk] = mapping(laz[k], dat[lk])
        dat[rk] = mapping(laz[k], dat[rk])
        if (lk < n) laz[lk] = composition(laz[k], laz[lk])
        if (rk < n) laz[rk] = composition(laz[k], laz[rk])
        laz[k] = id
    }

    private fun pushTo(k: Int) {
        for (i in log downTo 1) push(k shr i)
    }

    private fun pushTo(lk: Int, rk: Int) {
        for (i in log downTo 1) {
            if (lk shr i shl i != lk) push(lk shr i)
            if (rk shr i shl i != rk) push(rk shr i)
        }
    }

    private fun updateFrom(k: Int) {
        var vk = k
        vk = vk shr 1
        while (vk > 0) {
            dat[vk] = op(dat[vk shl 1], dat[vk shl 1 or 1])
            vk = vk shr 1
        }
    }

    private fun updateFrom(lk: Int, rk: Int) {
        for (i in 1..log) {
            if (lk shr i shl i != lk) {
                val lki = lk shr i
                dat[lki] = op(dat[lki shl 1], dat[lki shl 1 or 1])
            }
            if (rk shr i shl i != rk) {
                val rki = rk - 1 shr i
                dat[rki] = op(dat[rki shl 1], dat[rki shl 1 or 1])
            }
        }
    }

    operator fun set(p: Int, x: S) {
        var vp = p
//        exclusiveRangeCheck(vp)
        vp += n
        pushTo(vp)
        dat[vp] = x
        updateFrom(vp)
    }

    operator fun get(p: Int): S {
        var vp = p
//        exclusiveRangeCheck(vp)
        vp += n
        pushTo(vp)
        return dat[vp]
    }

    fun prod(l: Int, r: Int): S {
        var vl = l
        var vr = r
//        require(vl <= vr) { String.format("Invalid range: [%d, %d)", vl, vr) }
//        inclusiveRangeCheck(vl)
//        inclusiveRangeCheck(vr)
        if (vl == vr) return e
        vl += n
        vr = n+n
        pushTo(vl, vr)
        var sumLeft = e
        var sumRight = e
        while (vl < vr) {
            if (vl and 1 == 1) sumLeft = op(sumLeft, dat[vl++])
            if (vr and 1 == 1) sumRight = op(dat[--vr], sumRight)
            vl = vl shr 1
            vr = vr shr 1
        }
        return op(sumLeft, sumRight)
    }

    fun allProd(): S {
        return dat[1]
    }

    fun apply(p: Int, f: F) {
        var vp = p
//        exclusiveRangeCheck(vp)
        vp += n
        pushTo(vp)
        dat[vp] = mapping(f, dat[vp])
        updateFrom(vp)
    }

    fun apply(l: Int, r: Int, f: F) {
        var vl = l
        var vr = r
//        require(vl <= vr) { String.format("Invalid range: [%d, %d)", vl, vr) }
//        inclusiveRangeCheck(vl)
//        inclusiveRangeCheck(vr)
        if (vl == vr) return
        vl += n
        vr += n
        pushTo(vl, vr)
        var l2 = vl
        var r2 = vr
        while (l2 < r2) {
            if (l2 and 1 == 1) {
                dat[l2] = mapping(f, dat[l2])
                if (l2 < n) laz[l2] = composition(f, laz[l2])
                l2++
            }
            if (r2 and 1 == 1) {
                r2--
                dat[r2] = mapping(f, dat[r2])
                if (r2 < n) laz[r2] = composition(f, laz[r2])
            }
            l2 = l2 shr 1
            r2 = r2 shr 1
        }
        updateFrom(vl, vr)
    }

    private fun exclusiveRangeCheck(p: Int) {
        if (p < 0 || p >= MAX) {
            throw IndexOutOfBoundsException(String.format("Index %d is not in [%d, %d).", p, 0, MAX))
        }
    }

    private fun inclusiveRangeCheck(p: Int) {
        if (p < 0 || p > MAX) {
            throw IndexOutOfBoundsException(String.format("Index %d is not in [%d, %d].", p, 0, MAX))
        }
    }

    // **************** DEBUG **************** //
    private var indent = 6
    fun setIndent(newIndent: Int) {
        indent = newIndent
    }

    override fun toString(): String {
        return toSimpleString()
    }

    private fun simulatePushAll(): Array<S> {
        val simDat = Arrays.copyOf(dat, 2 * n)
        val simLaz = Arrays.copyOf(laz, 2 * n)
        for (k in 1 until n) {
            if (simLaz[k] === id) continue
            val lk = k shl 1
            val rk = k shl 1 or 1
            simDat[lk] = mapping(simLaz[k], simDat[lk])
            simDat[rk] = mapping(simLaz[k], simDat[rk])
            if (lk < n) simLaz[lk] = composition(simLaz[k], simLaz[lk])
            if (rk < n) simLaz[rk] = composition(simLaz[k], simLaz[rk])
            simLaz[k] = id
        }
        return simDat
    }

    fun toDetailedString(): String {
        return toDetailedString(1, 0, simulatePushAll())
    }

    private fun toDetailedString(k: Int, sp: Int, dat: Array<S>): String {
        if (k >= n) return indent(sp) + dat[k]
        var s = ""
        s += toDetailedString(k shl 1 or 1, sp + indent, dat)
        s += "\n"
        s += indent(sp) + dat[k]
        s += "\n"
        s += toDetailedString(k shl 1, sp + indent, dat)
        return s
    }

    fun toSimpleString(): String {
        val dat = simulatePushAll()
        val sb = StringBuilder()
        sb.append('[')
        for (i in 0 until n) {
            sb.append(dat[i + n])
            if (i < n - 1) sb.append(',').append(' ')
        }
        sb.append(']')
        return sb.toString()
    }

    companion object {
        private fun indent(n: Int): String {
            var vn = n
            val sb = StringBuilder()
            while (vn-- > 0) sb.append(' ')
            return sb.toString()
        }
    }
}

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val n=readInt()
//    val vs=List(n){it*3}
    val vs=readIntArray(n)
    val q=readInt()
    val ps=List(q){
        val (l,r)=readInts(2)
        Pair(l-1,r)
//        Pair(0,it+1)
    }
    val inds=List(q){it}.sortedBy { i -> ps[i].second }
    val re=LongArray(q)
    var rb=0
    val stk= mutableListOf(Pair(11234567,-1))
    val st = LazySegTree(
        Array(n){Pair(0L,1)},
        { a, b -> Pair(a.first + b.first, a.second + b.second) },
        Pair(0L, 0),
        { a, p -> Pair(a * p.second + p.first, p.second) },
        { a, b -> a + b },
        0
    )
    for(i in inds){
        val (l,r)=ps[i]
        while(rb<r){
//            println(rb)
            var lb=rb
            while(stk.last().first <= vs[rb]){
                st.apply(stk.last().second, lb, vs[rb]-stk.last().first)
                lb=stk.last().second
                stk.removeAt(stk.lastIndex)
            }
            stk.add(Pair(vs[rb],lb))
            st.apply(rb,vs[rb])
//            println("[$lb,${rb+1})${vs[rb]}")
            ++rb
        }
        re[i]=st.prod(l,r).first
    }
    println(re.joinToString(" "))
    pw.flush()
}