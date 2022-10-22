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
        println((0 until n).map { idx ->
            Array(n) { n - it }.also { arr ->
                if (idx + 1 == n) return@also
                arr[idx] = arr[idx + 1].also { arr[idx + 1] = arr[idx] }
            }.joinToString(" ")
        }.joinToString("\n"))
    }
}