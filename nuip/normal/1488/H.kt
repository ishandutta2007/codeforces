import java.io.PrintWriter

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
    val (n,q)=readVi()
    val vs=readVi().toIntArray()
    val qs=IntArray(q){readi()-1}
    val lt= arrayListOf(
        longArrayOf(0,0,0,0),
        longArrayOf(1,0,0,0),
        longArrayOf(1,1,0,0),
        longArrayOf(1,1,1,0)
    )
    val le= arrayListOf(
        longArrayOf(1,0,0,0),
        longArrayOf(1,1,0,0),
        longArrayOf(1,1,1,0),
        longArrayOf(1,1,1,1)
    )
    val gt= arrayListOf(
        longArrayOf(0,1,1,1),
        longArrayOf(0,0,1,1),
        longArrayOf(0,0,0,1),
        longArrayOf(0,0,0,0)
    )
    val ge= arrayListOf(
        longArrayOf(1,1,1,1),
        longArrayOf(0,1,1,1),
        longArrayOf(0,0,1,1),
        longArrayOf(0,0,0,1)
    )
    val st=SegTree(
        (0..n-2).map { i ->
            if (vs[i] == 0) {
                if (i + 1 < n - 1 && vs[i + 1] == 1) {
                    gt
                } else {
                    ge
                }
            } else {
                if (i + 1 == n - 1 || vs[i + 1] == 0) {
                    lt
                } else {
                    le
                }
            }
        }.toTypedArray(),
        {a,b ->
            arrayListOf(
                longArrayOf(
                    (a[0][0]*b[0][0]+a[0][1]*b[1][0]+a[0][2]*b[2][0]+a[0][3]*b[3][0])%998244353,
                    (a[0][0]*b[0][1]+a[0][1]*b[1][1]+a[0][2]*b[2][1]+a[0][3]*b[3][1])%998244353,
                    (a[0][0]*b[0][2]+a[0][1]*b[1][2]+a[0][2]*b[2][2]+a[0][3]*b[3][2])%998244353,
                    (a[0][0]*b[0][3]+a[0][1]*b[1][3]+a[0][2]*b[2][3]+a[0][3]*b[3][3])%998244353),
                longArrayOf(
                    (a[1][0]*b[0][0]+a[1][1]*b[1][0]+a[1][2]*b[2][0]+a[1][3]*b[3][0])%998244353,
                    (a[1][0]*b[0][1]+a[1][1]*b[1][1]+a[1][2]*b[2][1]+a[1][3]*b[3][1])%998244353,
                    (a[1][0]*b[0][2]+a[1][1]*b[1][2]+a[1][2]*b[2][2]+a[1][3]*b[3][2])%998244353,
                    (a[1][0]*b[0][3]+a[1][1]*b[1][3]+a[1][2]*b[2][3]+a[1][3]*b[3][3])%998244353),
                longArrayOf(
                    (a[2][0]*b[0][0]+a[2][1]*b[1][0]+a[2][2]*b[2][0]+a[2][3]*b[3][0])%998244353,
                    (a[2][0]*b[0][1]+a[2][1]*b[1][1]+a[2][2]*b[2][1]+a[2][3]*b[3][1])%998244353,
                    (a[2][0]*b[0][2]+a[2][1]*b[1][2]+a[2][2]*b[2][2]+a[2][3]*b[3][2])%998244353,
                    (a[2][0]*b[0][3]+a[2][1]*b[1][3]+a[2][2]*b[2][3]+a[2][3]*b[3][3])%998244353),
                longArrayOf(
                    (a[3][0]*b[0][0]+a[3][1]*b[1][0]+a[3][2]*b[2][0]+a[3][3]*b[3][0])%998244353,
                    (a[3][0]*b[0][1]+a[3][1]*b[1][1]+a[3][2]*b[2][1]+a[3][3]*b[3][1])%998244353,
                    (a[3][0]*b[0][2]+a[3][1]*b[1][2]+a[3][2]*b[2][2]+a[3][3]*b[3][2])%998244353,
                    (a[3][0]*b[0][3]+a[3][1]*b[1][3]+a[3][2]*b[2][3]+a[3][3]*b[3][3])%998244353)
            )

        },
        arrayListOf(
            longArrayOf(1,0,0,0),
            longArrayOf(0,1,0,0),
            longArrayOf(0,0,1,0),
            longArrayOf(0,0,0,1)
        )
    )
    for(q in qs){
        vs[q]=1-vs[q]
        if(vs[q]==1){
            st.set(q,
                if(q+1==n-1 || vs[q+1]==0){
                    lt
                }else{
                    le
                }
            )
            if(q>0){
                st.set(q-1,
                    if(vs[q-1]==0) gt
                    else le
                )
            }
        }else{
            st.set(q,
                if(q+1<n-1 && vs[q+1]==1){
                    gt
                }else{
                    ge
                })
            if(q>0){
                st.set(q-1,
                    if(vs[q-1]==0) ge
                    else lt
                )
            }
        }
        val a=st.allProd()
        var re=0L
        for(i in 0..3)for(j in 0..3) re+=a[i][j]
//        for(i in 0..n-2){
//            println("### $i")
//            println(st.get(i).map { r -> r.joinToString(" ") }.joinToString("\n"))
//        }
//        println(a.map { r -> r.joinToString(" ") }.joinToString("\n"))
        println(re%998244353)
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