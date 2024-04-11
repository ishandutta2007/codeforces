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
        var n = getInt()
        var a = TreeMap<Int, Int>()

        for (i in 0 until n) {
            var x = getInt()
            a[x] = a[x]?.inc() ?: 1
        }

        a.filter{ (K, V) -> V >= 3 }.firstNotNullOfOrNull { it }?.key ?: -1
    }.joinToString("\n"))
}