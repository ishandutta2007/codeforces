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
    var t = getInt()
    while (t-- > 0) {
        var (n, k) = Array(2) { getInt() }
        var ans = 0
        for (i in 0 until n) {
            var (l, r) = Array(2) { getInt() }
            if (l <= k)
                ans = maxOf(ans, r - k + 1)
        }
        println(ans)
    }
}