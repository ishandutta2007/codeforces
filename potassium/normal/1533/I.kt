import java.lang.AssertionError
import java.lang.StringBuilder
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

class dsu(n : Int) {
    var p = Array(n) { it }
    var sz = Array(n) { 1 }
    var dup = Array(n) { false }
    var minv = Array(n) { Integer.MAX_VALUE }

    fun find(u : Int) : Int = if (u == p[u]) u else { p[u] = find(p[u]); p[u] }

    fun union(u : Int, v : Int) {
        var pu = find(u)
        var pv = find(v)
        if (pu == pv) {
            dup[pu] = true
        }
        else {
            if (sz[pu] < sz[pv])
                pu = pv.also { pv = pu }
            p[pv] = pu
            sz[pu] += sz[pv]
            minv[pu] = minOf(minv[pu], minv[pv])
        }
    }
}

fun main() {
    var (n1, n2, m) = Array(3) { getInt() }
    var k = Array(n1) { getInt() }

    var dsu = dsu(n1 + n2)
    for (i in 0 until n1)
        dsu.minv[i] = k[i]

    for (i in 0 until m) {
        var (u, v) = Array(2) { getInt() }
        u--
        v--
        v += n1
        dsu.union(u, v)
    }

    var counted = Array(n1 + n2) { false }
    var ans = 0
    for (i in 0 until n1 + n2) {
        var pi = dsu.find(i)
        if (!counted[pi]) {
            counted[pi] = true
            if (!dsu.dup[pi])
                ans += dsu.minv[pi]
        }
    }

    println(ans)
}