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
    var a = MutableList<Long>(n) { getLong() }

    var m = TreeMap<Long, Int>()
    for (i in a)
        m.compute(i) { _, value -> if (value == null) 1 else value + 1 }

    var sum = a.sum()

    var ans = mutableListOf<Int>()
    for (i in a.indices) {
        sum -= a[i]
        if (sum % 2 == 1L) {
            sum += a[i]
            continue
        }

        m.compute(a[i]) { _, value -> value!! - 1 }

        var half = sum / 2
        if (m.containsKey(half) && m.get(half)!! > 0)
            ans.add(i + 1)

        sum += a[i]
        m.compute(a[i]) { _, value -> value!! + 1 }
    }

    println(ans.size)
    println(ans.joinToString(" "))
}