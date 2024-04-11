import java.util.*

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
    var t = readInt()
    while (t-- > 0) {
        var (n, k) = readInts()
        var a = readLongs()
        a = a.reversed()

        var ans = 0L
        for (i in k - 1 until n step k) {
            var sum = 0L
            for (j in i - (i / k) .. i) {
                sum += a[j]
            }

            ans = Math.max(ans, sum)
        }

        println(ans)
    }
}