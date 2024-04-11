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
        var (a, b) = readLine()!!.split(" ").map{ it.toLong() }

        var ans = Long.MAX_VALUE
        for (i in 0 until Long.MAX_VALUE) {
            var now = b + i
            if (now <= 1)
                continue

            var cost = i

            var tmp = a
            while (tmp > 0) {
                tmp /= now
                cost++
            }

            if (cost > ans)
                break

            ans = cost
        }

        println(ans)
    }
}