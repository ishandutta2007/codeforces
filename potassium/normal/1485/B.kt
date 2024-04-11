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
    var (n,q,k) = readLine()!!.split(" ").map{ it.toLong() }
    var a = readLine()!!.split(" ").map{ it.toLong() }

    while (q-- > 0) {
        var (l,r) = readLine()!!.split(" ").map{ it.toLong() }
        l--
        r--

        var ans = k + a[r.toInt()] - a[l.toInt()] - r + l - r + l - 1
        println(ans)
    }
}