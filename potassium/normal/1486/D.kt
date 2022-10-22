import java.util.*
import kotlin.system.exitProcess

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
    var (n, k) = arrayOf(getInt(), getInt())
    var a = MutableList(n) { getInt() }

    var l = 1; var r = n;
    while (r > l) {
        var mid = (l + r + 1) / 2

        var ps = MutableList(n) { 0 }
        for (i in 0 until n)
            ps[i] = (if (a[i] >= mid) 1 else -1) + (if (i > 0) ps[i - 1] else 0)

        var minv = 0
        var ok = false
        for (i in k - 1 until n) {
            if (i - k >= 0)
                minv = Math.min(minv, ps[i - k])

            if (ps[i] - minv >= 1)
                ok = true
        }

        if (ok) {
            l = mid
        }
        else {
            r = mid - 1
        }
    }

    println(l)
}