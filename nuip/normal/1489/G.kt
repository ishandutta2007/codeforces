import java.io.PrintWriter
class DSU(private val n: Int) {
    private val parentOrSize: IntArray = IntArray(n) { -1 }

    /**
     * Merge nodes.
     */
    fun merge(a: Int, b: Int): Int {
        if (a !in 0 until n) throw IndexOutOfBoundsException("a=$a")
        if (b !in 0 until n) throw IndexOutOfBoundsException("b=$b")
        var x = leader(a)
        var y = leader(b)
        if (x == y) return x
        if (-parentOrSize[x] < -parentOrSize[y]) {
            val tmp = x
            x = y
            y = tmp
        }
        parentOrSize[x] += parentOrSize[y]
        parentOrSize[y] = x
        return x
    }

    /**
     * True if two nodes are connected.
     */
    fun same(a: Int, b: Int): Boolean {
        if (a !in 0 until n) throw IndexOutOfBoundsException("a=$a")
        if (b !in 0 until n) throw IndexOutOfBoundsException("b=$b")
        return leader(a) == leader(b)
    }

    /**
     * Get its leader node.
     */
    fun leader(a: Int): Int {
        return if (parentOrSize[a] < 0) {
            a
        } else {
            parentOrSize[a] = leader(parentOrSize[a])
            parentOrSize[a]
        }
    }

    /**
     * A group's size.
     */
    fun size(a: Int): Int {
        if (a !in 0 until n) throw IndexOutOfBoundsException("" + a)
        return -parentOrSize[leader(a)]
    }

    /**
     * Group by leader.
     */
    fun groups(): ArrayList<ArrayList<Int>> {
        val leaderBuf = IntArray(n)
        val groupSize = IntArray(n)
        for (i in 0 until n) {
            leaderBuf[i] = leader(i)
            groupSize[leaderBuf[i]]++
        }
        val result = ArrayList<ArrayList<Int>>(n)
        for (i in 0 until n) {
            result.add(ArrayList(groupSize[i]))
        }
        for (i in 0 until n) {
            result[leaderBuf[i]].add(i)
        }
        result.removeIf { it.isEmpty() }
        return result
    }
}

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val (n,m)=readVi()
    val vs=readVl()
    val es= MutableList(m){
        val (x,y,w)=readVl()
        Triple(w,x.toInt()-1,y.toInt()-1)
    }
    val mini=vs.indexOf(vs.minOrNull())
    repeat(n){i -> es.add(Triple(vs[i]+vs[mini],i,mini)) }
    es.sortBy { tr -> tr.first }
    val uf=DSU(n)
    var re=0L
    for((w,x,y) in es){
        if(uf.same(x,y)) continue
        uf.merge(x,y)
        re+=w
    }
    println(re)
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(' ')
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