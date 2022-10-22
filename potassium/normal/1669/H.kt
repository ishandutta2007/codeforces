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
        var (n,k) = Array(2) { getInt() }

        var cnt = Array(31) { 0 }
        for (i in 0 until n) {
            var x = getInt()
            for (j in 0 until 50) {
                if ((x and 1) > 0)
                    cnt[j]++
                x /= 2
                if (x == 0) break
            }
        }

        var ans = 0
        for (i in 30 downTo 0) {
            var need = n - cnt[i]
            if (need <= k) {
                k -= need
                ans = ans or (1 shl i)
            }
        }

        ans
    }.joinToString("\n"))
}