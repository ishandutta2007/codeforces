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
        val b = MutableList<Int>(n) { 0 }
        for (i in 0 until n)
            b[i] = getInt()

        var ans = 0L

        var shift = 0L
        var sum = 1L
        val m = TreeMap<Long, Long>()
        m[0] = 1

        for (x in b) {
            var zero = m.getOrDefault(-shift, 0)

            shift += x
            m[x - shift] = sum

            sum *= 2
            sum -= zero
            sum %= MOD107
        }

        sum %= MOD107
        sum += MOD107
        sum %= MOD107

        println(sum)
    }
}