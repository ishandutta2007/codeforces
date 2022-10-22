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

        var ans = MutableList<Int>(n) { -1 }
        for (i in 0 until n - 3 step 2) {
            ans[i] = i + 1
            ans[i + 1] = i
        }

        if (n % 2 == 1) {
            ans[n - 3] = n - 1
            ans[n - 2] = n - 3
            ans[n - 1] = n - 2
        }
        else {
            ans[n - 2] = n - 1
            ans[n - 1] = n - 2
        }

        println(ans.map{ it + 1 }.joinToString(" "))
    }
}