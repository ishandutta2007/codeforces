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
        var a = MutableList(n) { getInt() }

        var cnt = MutableList(3) { 0 }
        for (i in a)
            cnt[i % 3]++

        var avg = n / 3
        var ans = 0
        for (i in 0 until 2) {
            for (j in 0 until 3) {
                var take = Math.max(0, cnt[j] - avg)
                cnt[j] -= take
                cnt[(j + 1) % 3] += take
                ans += take
            }
        }

        println(ans)
    }
}