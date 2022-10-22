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
    var n = getInt()

    fun ask(l : Int, r : Int) : Int {
        println("? ${l + 1} ${r + 1}")
        return getInt() - 1
    }

    fun done(ans : Int) {
        println("! ${ans + 1}")
        exitProcess(0)
    }

    var p = ask(0, n - 1)
    var l = 0; var r = n - 1
    if (l == p) l++
    if (r == p) r--

    while (r > l) {
        var mid = (l + r) / 2

        var isLeft = false
        if (p <= mid) {
            var res = ask(0, mid)
            isLeft = (res == p)
        }
        else {
            var res = ask(mid + 1, n - 1)
            isLeft = !(res == p)
        }

        if (isLeft) {
            r = mid
        }
        else {
            l = mid + 1
        }

        if (l == p) l++
        if (r == p) r--
    }

    done(l)
}