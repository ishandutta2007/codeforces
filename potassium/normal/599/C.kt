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
    var a = MutableList(n) { getInt() }

    var order = MutableList(n) { Pair(a[it], it) }
    order.sortWith { x, y -> if (x.first != y.first) x.first.compareTo(y.first) else x.second.compareTo(y.second) }

    var ps = 0
    var ans = 0
    for (i in 0 until n) {
        ps = maxOf(ps, order[i].second)
        if (ps == i)
            ans++
    }

    println(ans)
}