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
        var n = getInt()
        var a = MutableList<Int>(n) { getInt() }

        var ans = 0L
        for (i in 0 until n) {
            var rem = ((-i - 2) % a[i] + a[i]) % a[i]
            for (j in rem until n step a[i]) {
                if (i == j) continue
                if (1L * a[i] * a[j] == 2L + i + j) {
                    ans++
                }
            }
        }

        println(ans / 2)
    }
}