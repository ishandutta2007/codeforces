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

        var maxv = 2 * n - 1
        var sqrt = Math.sqrt(maxv.toDouble()).toInt()

        for (i in Math.max(sqrt - 5, 0) until sqrt + 5)
            if (i * i > maxv) {
                sqrt = i - 1;
                break;
            }

        println((sqrt - 1) / 2)
    }
}