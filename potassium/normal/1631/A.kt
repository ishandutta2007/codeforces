import java.lang.AssertionError
import java.lang.StringBuilder
import java.util.*
import kotlin.math.*

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
        var a = Array(n) { getInt() }
        var b = Array(n) { getInt() }

        var x = 0
        var y = 0
        for (i in 0 until n) {
            x = max(x, max(a[i], b[i]))
            y = max(y, min(a[i], b[i]))
        }

        println(x * y)
    }
}