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
    var n = getInt()
    var k = getLong()
    var x = getLong()

    var a = MutableList<Long>(n) { getLong() }
    a.sort()

    var cost = mutableListOf<Long>()
    for (i in 0 until n - 1) {
        val dist = a[i + 1] - a[i]
        cost.add(maxOf(0, (dist - 1) / x))
    }
    cost.sortDescending()

    var ans = n
    while (!cost.isEmpty() && cost.last() <= k) {
        ans--
        k -= cost.last()
        cost.removeLast()
    }

    println(ans)
}