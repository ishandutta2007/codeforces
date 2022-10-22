import java.lang.AssertionError
import java.math.BigInteger
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
        val s = getInput()
        val n = s.length

        var last = MutableList(2) { -1 }
        var ans = 0L
        var l = 0
        for ((idx, ch) in s.withIndex()) {
            if (ch != '?') {
                val num = ch - '0'
                var sameMatch = last[num] == -1 || (idx - last[num]) % 2 == 0
                var diffMatch = last[num xor 1] == -1 || (idx - last[num xor 1]) % 2 == 1
                if (!sameMatch || !diffMatch) {
                    l = maxOf(last[0], last[1]) + 1
                    last[0] = -1
                    last[1] = -1
                }
                last[num] = idx
            }

            ans += (idx - l + 1)
        }

        println(ans)
    }
}