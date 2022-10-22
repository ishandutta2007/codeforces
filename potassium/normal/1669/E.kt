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
        var cnt1 = Array(26) { 0 }
        var cnt2 = Array(26) { 0 }
        var cnt3 = Array(26 * 26) { 0 }

        for (i in 0 until n) {
            var s = getInput()
            var a = s[0] - 'a'
            var b = s[1] - 'a'

            cnt1[a]++
            cnt2[b]++
            cnt3[a * 26 + b]++
        }

        var ans = 0L
        for (i in 0 until 26) ans += cnt1[i] * (cnt1[i] - 1) / 2
        for (i in 0 until 26) ans += cnt2[i] * (cnt2[i] - 1) / 2
        for (i in 0 until 26 * 26) ans -= cnt3[i] * (cnt3[i] - 1) / 2 * 2

        ans
    }.joinToString("\n"))
}