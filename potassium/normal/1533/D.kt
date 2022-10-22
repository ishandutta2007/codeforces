import java.lang.AssertionError
import java.lang.StringBuilder
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

fun main() {
    var (n, m) = Array(2) { getInt() }
    var cnt = TreeMap<String, Int>()
    for (i in 0 until n) {
        var s = getInput()
        cnt.compute(s) { _, value -> if (value == null) 1 else value + 1 }
    }

    var q = getInt()
    while (q-- > 0) {
        var s = getInput()
        var minor = TreeSet<String>()
        for (i in 0 .. m) {
            var now = s.substring(0, i) + s.substring(i + 1, m + 1)
            minor.add(now)
        }
        var ans = 0
        for (i in minor)
            ans += cnt[i] ?: 0
        println(ans)
    }
}