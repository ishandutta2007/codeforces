import java.lang.AssertionError
import java.util.*

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}
fun binpow(b : Long, p : Long, mod : Long) : Long {
    var pw = p
    var cur = b
    var ans = 1L
    while (pw > 0) {
        if ((pw and 1) > 0)
            ans = (ans * cur) % mod

        cur = (cur * cur) % mod
        pw = pw shr 1
    }
    return ans
}


class DSU(n : Int) {
    val par = MutableList(n) { it }
    val sz = MutableList(n) { 1 }

    fun find(u : Int) : Int {
        return if (u == par[u]) u else { par[u] = find(par[u]); par[u] }
    }

    fun union(u : Int, v : Int) : Boolean {
        var ur = find(u)
        var vr = find(v)

        if (ur == vr)
            return false

        if (sz[ur] < sz[vr])
            ur = vr.also { vr = ur }

        par[vr] = ur
        sz[ur] += sz[vr]

        return true
    }
}

fun main() {
    var (n,m) = arrayOf(getInt(), getInt())
    var a = MutableList(n) { getLong() }

    var edges = mutableListOf<Pair<Long, Pair<Int, Int>>>()
    for (i in 0 until m) {
        var u = getInt(); u--
        var v = getInt(); v--
        var w = getLong()
        edges.add(Pair(w, Pair(u, v)))
    }

    val src = a.minOrNull()!!.let { a.indexOf(it) }
    for (u in 0 until n) {
        if (u != src)
            edges.add(Pair(a[u] + a[src], Pair(u, src)))
    }

    edges.sortBy { it.first }

    var dsu = DSU(n)
    var ans = 0L
    for ((w, e) in edges) {
        var (u, v) = e

        if (dsu.union(u, v))
            ans += w
    }

    println(ans)
}