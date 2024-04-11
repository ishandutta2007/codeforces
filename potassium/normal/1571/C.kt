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
        var n = getInt()

        var minK = 0
        var maxK = 1000000
        for (i in 0 until n) {
            var (s,t) = Array(2) { getInput() }
            var r = getInt()

            var same = 0
            while (same + 1 <= s.length && same + 1 <= t.length && s[s.length - same - 1] == t[t.length - same - 1])
                same++

            if (r == 0) minK = Math.max(minK, same + 1)
            if (r == 1) maxK = Math.min(maxK, same)
        }

        var ans = Math.max(maxK - minK + 1, 0)
        println(ans)
        println(Array(ans) { minK + it }.joinToString(" "))
    }
}