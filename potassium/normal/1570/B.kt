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
    var a = Array(2) { getInt() }
    var k = Array(2) { getInt() }
    var n = getInt()

    if (k[0] > k[1]) {
        a[0] = a[1].also{ a[1] = a[0] }
        k[0] = k[1].also{ k[1] = k[0] }
    }

    var ans1 = Math.max(0, n + a[0] + a[1] - a[0] * k[0] - a[1] * k[1])
    var ans2 = if (a[0] * k[0] <= n) (n - a[0] * k[0]) / k[1] + a[0] else n / k[0]

    println("$ans1 $ans2")
}