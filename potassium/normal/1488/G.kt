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

    var ans = MutableList(n) { 0 }
    for (i in 1 .. n)
        for (j in i * 2 .. n step i) {
            ans[j - 1]++
            ans[i - 1]--
        }

    ans.sortDescending()
    for (i in 1 until n)
        ans[i] += ans[i - 1]

    println(ans.joinToString(" "))
}