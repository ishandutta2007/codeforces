import java.util.*
import kotlin.collections.ArrayDeque

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

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
    solve()
}

fun solve() {
    var (n, k) = readInts()
    var a = readLongs().sorted()
    var ps = Array<Long>(n) { 0 }
    for (i in ps.indices) {
        ps[i] = a[i]
        if (i > 0)
            ps[i] += ps[i - 1]
    }

    fun get(l : Int, r : Int) : Long {
        return ps[r] - (if (l - 1 < 0) 0 else ps[l - 1])
    }

    var dp = Array<Array<Long>>(n + 1) { Array<Long>(k + 1) { -1_000_000_000_000 } }
    for (k in 0 .. k)
        dp[0][k] = 0

    for (i in 0 until n) {
        for (l in 0 .. k) {
            dp[i + 1][l] = dp[i][l]
        }

        for (j in i - 1 downTo 0 step 2) {
            var mid = (i + j + 1) / 2
            var jump = i - mid + 1
            for (l in jump .. k) {
                dp[i + 1][l] = Math.max(dp[i + 1][l], dp[j + 1][l - jump] + get(mid, i) - get(j, mid - 1))
            }
        }
    }

    var ans = 0L
    for (l in 0 .. k)
        ans = Math.max(ans, dp[n][l])

    println(ans)
}