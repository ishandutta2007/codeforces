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
    var m = Array<Int>(200007) { 0 }
    var lp = 1; var rp = 0

    var q = getInt()
    while (q-- > 0) {
        var cmd = getString()
        var id = getInt()

        if (cmd == "L") {
            m[id] = --lp
            continue
        }

        if (cmd == "R") {
            m[id] = ++rp
            continue
        }

        if (cmd == "?") {
            var pos = m[id]
            println(Math.min(pos - lp, rp - pos))
            continue
        }

        myAssert(false)
    }
}