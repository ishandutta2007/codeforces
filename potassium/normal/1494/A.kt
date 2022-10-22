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
        var s = getString()

        var ans = false
        for (mask in 0 .. 7) {
            var bal = 0
            var can = true
            for (ch in s) {
                if (mask and (1 shl (ch - 'A')) > 0) bal++; else bal--;
                if (bal < 0) {
                    can = false
                    break
                }
            }

            if (bal != 0)
                can = false

            if (can)
                ans = true
        }

        println(if (ans) "YES" else "NO")
    }
}