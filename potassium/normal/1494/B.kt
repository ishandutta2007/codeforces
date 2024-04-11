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
        var a = Array<Int>(4) { getInt() }

        var ans = false
        for (mask in 0 .. 15) {
            var tmp = Array<Int>(4) { a[it] }
            for (b in 0 until 4) {
                var bit = 1 shl b
                if (mask and bit > 0) {
                    tmp[b]--
                    tmp[(b + 1) % 4]--
                }
            }

            var can = true
            for (i in tmp)
                if (i > n - 2 || i < 0)
                    can = false

            if (can)
                ans = true
        }

        println(if (ans) "YES" else "NO")
    }
}