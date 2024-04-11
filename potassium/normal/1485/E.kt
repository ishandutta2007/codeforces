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

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var n = getInt()
        val g = MutableList<MutableList<Int>>(n + 1) { MutableList<Int>(0) { 0 } }
        val par = MutableList<Int>(n + 1) { 0 }

        for (i in 2 .. n) {
            var v = getInt()
            g[i].add(v)
            g[v].add(i)
        }

        val a = MutableList<Int>(n + 1) { 0 }
        for (i in 2 .. n)
            a[i] = getInt()

        val dep = MutableList<Int>(n + 1) { Integer.MAX_VALUE }
        val dp = MutableList<Long>(n + 1) { 0L }
        var maxDep = 0
        var depths: MutableList<MutableList<Int>>

        run {
            dep[1] = 0
            val q = ArrayDeque<Int>()
            q.push(1)

            while (!q.isEmpty()) {
                var now = q.pop()

                for (v in g[now]) {
                    if (dep[v] > dep[now] + 1) {
                        dep[v] = dep[now] + 1
                        par[v] = now
                        q.push(v)
                    }
                }
            }

            for (i in 1 .. n)
                maxDep = Math.max(maxDep, dep[i])

            if (maxDep == Integer.MAX_VALUE) throw AssertionError()

            depths = MutableList<MutableList<Int>>(maxDep + 1) { MutableList<Int>(0) { 0 } }
            for (u in 1 .. n)
                depths[dep[u]].add(u)

            for (i in 1 .. maxDep)
                depths[i].sortBy{ a[it] }
        }

        for (d in 2 .. maxDep) {
            for (u in depths[d]) {
                var p = par[u]
                dp[u] = dp[p] + Math.max(a[p] - a[depths[d - 1].first()], a[depths[d - 1].last()] - a[p])
            }

            var maxv1 = Long.MIN_VALUE
            var maxv2 = Long.MIN_VALUE
            for (u in depths[d]) {
                var p = par[u]
                maxv1 = Math.max(maxv1, dp[p] - a[p])
                maxv2 = Math.max(maxv2, dp[p] + a[p])
            }

            for (u in depths[d]) {
                var p = par[u]
                dp[u] = Math.max(dp[u], maxv1 + a[p])
                dp[u] = Math.max(dp[u], maxv2 - a[p])
            }
        }

        var ans = 0L
        for (u in depths[maxDep]) {
            var value = dp[u] + Math.max(a[u] - a[depths[maxDep].first()], a[depths[maxDep].last()] - a[u])
            ans = Math.max(ans, value)
        }

        println(ans)
    }
}