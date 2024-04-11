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
        var a = MutableList<Int>(2 * n) { 0 }
        for (i in 0 until 2 * n)
            a[i] = getInt()

        a.sort()
        for (i in 1 until n step 2) {
            var t = a[i]
            a[i] = a[2 * n - 1 - i]
            a[2 * n - 1 - i] = t
        }

        println(a.joinToString(" "))
    }
}