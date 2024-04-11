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
        var x = MutableList(n) { 0L }; var y = MutableList(n) { 0L }
        for (i in 0 until n) {
            x[i] = getLong()
            y[i] = getLong()
        }

        x.sort()
        y.sort()

        var ans = 1L
        if (n % 2 == 0) {
            ans *= x[n / 2] - x[n / 2 - 1] + 1
            ans *= y[n / 2] - y[n / 2 - 1] + 1
        }

        println(ans)
    }
}