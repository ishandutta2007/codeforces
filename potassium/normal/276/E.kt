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

class BIT(n : Int) {
    var a = MutableList(n + 1) { 0 }
    val N = n

    fun upd(idx : Int, v : Int) {
        var i = idx
        while (i <= N) {
            a[i] += v
            i += i and -i
        }
    }

    fun qry(idx : Int) : Int {
        var i = idx
        var sum = 0
        while (i > 0) {
            sum += a[i]
            i -= i and -i
        }
        return sum
    }
}

fun main() {
    var (n,q) = arrayOf(getInt(), getInt())
    var g = MutableList(n + 7) { mutableListOf<Int>() }

    for (i in 0 until n - 1) {
        var (u,v) = arrayOf(getInt(), getInt())
        g[u].add(v)
        g[v].add(u)
    }

    var ch = MutableList(g[1].size) { MutableList<Int>(1) { 1 } }
    var grp = MutableList(n + 7) { -1 }
    var idx = MutableList(n + 7) { -1 }

    fun dfs(u : Int, p : Int) {
        if (p != 1) grp[u] = grp[p]
        idx[u] = if (p == 1) 1 else idx[p] + 1
        ch[grp[u]].add(u)

        for (v in g[u])
            if (v != p)
                dfs(v, u)
    }
    g[1].forEachIndexed { id, u ->
        grp[u] = id

        dfs(u, 1)
    }

    var ps = MutableList(g[1].size) { BIT(ch[it].size + 7) }
    var d1 = BIT(n + 7)
    var n1 = 0

    while (q-- > 0) {
        var cmd = getInt()

        if (cmd == 0) {
            var (u,x,d) = arrayOf(getInt(), getInt(), getInt())

            if (u == 1) {
                n1 += x
                d1.upd(1, x)
                d1.upd(d + 1, -x)
            }
            else {
                var dist1 = idx[u]
                var gp = grp[u]

                ps[gp].upd(Math.max(1, dist1 - d), x)
                ps[gp].upd(dist1 + d + 1, -x)

                if (d >= dist1) {
                    n1 += x
                    var rd1 = d - dist1
                    d1.upd(1, x)
                    d1.upd(rd1 + 1, -x)

                    ps[gp].upd(1, -x)
                    ps[gp].upd(rd1 + 1, x)
                }
            }
        }
        else {
            var u = getInt()

            println(if (u == 1) n1 else ps[grp[u]].qry(idx[u]) + d1.qry(idx[u]))
        }
    }
}