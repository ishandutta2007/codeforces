import java.io.PrintWriter
import java.lang.Integer.max

class SegTree<S>(n: Int, op: (S, S) -> S, e: S) {
    private val max: Int = n
    private val n: Int
    private val op: (S, S) -> S
    private val e: S
    private val data: Array<S>

    init {
        var k = 1
        while (k < n) k = k shl 1
        this.n = k
        this.e = e
        this.op = op
        @Suppress("UNCHECKED_CAST")
        data = Array(this.n shl 1) { this.e as Any } as Array<S>
        java.util.Arrays.fill(data, this.e)
    }

    constructor(dat: Array<S>, op: (S, S) -> S, e: S) : this(dat.size, op, e) {
        build(dat)
    }

    private fun build(dat: Array<S>) {
        val l = dat.size
        System.arraycopy(dat, 0, data, n, l)
        for (i in n - 1 downTo 1) {
            data[i] = op(data[i shl 1 or 0], data[i shl 1 or 1])
        }
    }

    operator fun set(p: Int, x: S) {
        var vp = p
        exclusiveRangeCheck(vp)
        data[n.let { vp += it; vp }] = x
        vp = vp shr 1
        while (vp > 0) {
            data[vp] = op(data[vp shl 1 or 0], data[vp shl 1 or 1])
            vp = vp shr 1
        }
    }

    operator fun get(p: Int): S {
        exclusiveRangeCheck(p)
        return data[p + n]
    }

    fun prod(l: Int, r: Int): S {
        var vl = l
        var vr = r
        require(vl <= vr) { String.format("Invalid range: [%d, %d)", vl, vr) }
        inclusiveRangeCheck(vl)
        inclusiveRangeCheck(vr)
        var sumLeft = e
        var sumRight = e
        vl += n
        vr += n
        while (vl < vr) {
            if (vl and 1 == 1) sumLeft = op(sumLeft, data[vl++])
            if (vr and 1 == 1) sumRight = op(data[--vr], sumRight)
            vl = vl shr 1
            vr = vr shr 1
        }
        return op(sumLeft, sumRight)
    }

    fun allProd(): S {
        return data[1]
    }

    fun maxRight(l: Int, f: (S) -> Boolean): Int {
        var vl = l
        inclusiveRangeCheck(vl)
        require(f(e)) { "Identity element must satisfy the condition." }
        if (vl == max) return max
        vl += n
        var sum = e
        do {
            vl = vl shr Integer.numberOfTrailingZeros(vl)
            if (!f(op(sum, data[vl]))) {
                while (vl < n) {
                    vl = vl shl 1
                    if (f(op(sum, data[vl]))) {
                        sum = op(sum, data[vl])
                        vl++
                    }
                }
                return vl - n
            }
            sum = op(sum, data[vl])
            vl++
        } while (vl and -vl != vl)
        return max
    }

    fun minLeft(r: Int, f: (S) -> Boolean): Int {
        var vr = r
        inclusiveRangeCheck(vr)
        require(f(e)) { "Identity element must satisfy the condition." }
        if (vr == 0) return 0
        vr += n
        var sum = e
        do {
            vr--
            while (vr > 1 && vr and 1 == 1) vr = vr shr 1
            if (!f(op(data[vr], sum))) {
                while (vr < n) {
                    vr = vr shl 1 or 1
                    if (f(op(data[vr], sum))) {
                        sum = op(data[vr], sum)
                        vr--
                    }
                }
                return vr + 1 - n
            }
            sum = op(data[vr], sum)
        } while (vr and -vr != vr)
        return 0
    }

    private fun exclusiveRangeCheck(p: Int) {
        if (p < 0 || p >= max) {
            throw IndexOutOfBoundsException(String.format("Index %d out of bounds for the range [%d, %d).", p, 0, max))
        }
    }

    private fun inclusiveRangeCheck(p: Int) {
        if (p < 0 || p > max) {
            throw IndexOutOfBoundsException(String.format("Index %d out of bounds for the range [%d, %d].", p, 0, max))
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

    fun toDetailedString(): String {
        return toDetailedString(1, 0)
    }

    private fun toDetailedString(k: Int, sp: Int): String {
        if (k >= n) return indent(sp) + data[k]
        var s = ""
        s += toDetailedString(k shl 1 or 1, sp + indent)
        s += "\n"
        s += indent(sp) + data[k]
        s += "\n"
        s += toDetailedString(k shl 1 or 0, sp + indent)
        return s
    }

    fun toSimpleString(): String {
        val sb = StringBuilder()
        sb.append('[')
        for (i in 0 until n) {
            sb.append(data[i + n])
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
    val T=readi()
    repeat(T){
        val n=readi()
        val vs=readVi().map{x -> x-1}
        val st=SegTree(n, {a,b->max(a,b)}, 0)
        val prev=IntArray(n){-1}
        for(i in 0..n-1){
            if(prev[vs[i]]>=0) {
                val mx=st.prod(prev[vs[i]]+1,i)
                st.set(prev[vs[i]],mx+2)
            }else{
                prev[vs[i]]=i
            }
            st.set(i,1)
        }
        println(st.allProd())
    }
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }
fun reads() = next()
fun readi() = nint()
fun readl() = nlong()
fun readd() = ndouble()
fun readVs() = nlstring()
fun readVi() = nlint()
fun readVl() = nllong()
fun readVd() = nldouble()
fun read() = readl()
fun readV() = readVl()