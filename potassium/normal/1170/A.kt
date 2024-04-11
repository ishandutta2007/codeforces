import java.lang.AssertionError
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
    var q = getInt()
    while (q-- > 0) {
        var (x, y) = Array(2) { getLong() }
        var c = minOf(x, y) - 1
        var a = x - c
        var b = y - c
        println("$a $b $c")
    }
}