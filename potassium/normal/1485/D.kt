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
    var v = 720720

    var n = getInt()
    var m = getInt()

    var ans = MutableList(n) { MutableList(m) { getInt() } }
    for (i in 0 until n) {
        for (j in 0 until m) {
            if ((i + j) % 2 == 0) {
                ans[i][j] *= ans[i][j]
                ans[i][j] *= ans[i][j]
            }
            else {
                ans[i][j] = 0
            }
            ans[i][j] += v
        }
    }

    for (i in ans)
        println(i.joinToString(" "))
}