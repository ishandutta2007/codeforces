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
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}
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
    var (n,m,k) = readLine()!!.split(" ").map{ it.toInt() }
    var a = MutableList(n) { getInt() }

    var l = 0; var r = n
    while (r > l) {
        var mid = (l + r) / 2

        var curBox = k
        var remBox = m
        for (i in mid until n) {
            if (curBox + a[i] > k) {
                curBox = 0
                remBox--
            }

            curBox += a[i]
        }

        if (remBox < 0) {
            l = mid + 1
        }
        else {
            r = mid
        }
    }

    println(n - l)
}