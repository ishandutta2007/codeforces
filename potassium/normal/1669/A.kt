import java.lang.AssertionError
import java.lang.StringBuilder
import java.math.BigInteger
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
    println((0 until t).map {
        var rating = getInt()
        "Division " + (4 - (if (rating >= 1400) 1 else 0) - (if (rating >= 1600) 1 else 0) - (if (rating >= 1900) 1 else 0))
    }.joinToString("\n"))
}