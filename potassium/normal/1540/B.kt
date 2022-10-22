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

fun binpow(base : Long, pow : Long, mod : Long) : Long {
    var ans = 1L
    var b = base
    var p = pow
    while (p > 0) {
        if (p % 2 == 1L) ans = ans * b % mod
        p = p shr 1
        b = b * b % mod
    }
    return ans
}

fun main() {
    var n = getInt()
    val g = Array<MutableList<Int>>(n + 1) { mutableListOf() }

    for (i in 0 until n - 1) {
        var (u, v) = arrayOf(getInt(), getInt())
        g[u].add(v)
        g[v].add(u)
    }

    val lca = Array(n + 1) { Array(n + 1) { Array(n + 1) { -1 } } }
    val dist = Array(n + 1) { Array(n + 1) { 0 } }
    for (root in 1 .. n) {
        var dep = Array(n + 1) { 0 }
        var par = Array(n + 1) { -1 }
        fun dfs(u : Int, p : Int) {
            par[u] = p
            dep[u] = if (p == -1) 0 else dep[p] + 1
            dist[root][u] = if (p == -1) 0 else dist[root][p] + 1
            for (v in g[u])
                if (v != p)
                    dfs(v, u)
        }
        dfs(root, -1)

        fun find_lca(u : Int, v : Int) : Int {
            if (lca[root][u][v] != -1) return lca[root][u][v]
            if (u == v)
                lca[root][u][v] = u
            else if (dep[u] < dep[v])
                lca[root][u][v] = find_lca(u, par[v])
            else
                lca[root][u][v] = find_lca(par[u], v)
            return lca[root][u][v]
        }

        for (u in 1 .. n)
            for (v in 1 .. n)
                find_lca(u, v)
    }

    val inv2 = binpow(2L, MOD107 - 2, MOD107)
    val prob = Array(n + 1) { Array(n + 1) { 0L } }
    for (i in 0 .. n) {
        for (j in 0 .. n) {
            if (i == 0) prob[i][j] = 1
            if (j == 0) prob[i][j] = 0
            if (i > 0 && j > 0)
                prob[i][j] = (prob[i - 1][j] + prob[i][j - 1]) * inv2 % MOD107
        }
    }

    var ans = 0L
    for (i in 1 .. n) {
        for (j in 1 until i) {
            for (u in 1 .. n) {
                var pu = lca[u][i][j]
                var di = dist[pu][i]
                var dj = dist[pu][j]
                ans += prob[di][dj]
            }
        }
    }

    ans %= MOD107
    ans *= binpow(n.toLong(), MOD107 - 2, MOD107)
    ans %= MOD107

    println(ans)
}