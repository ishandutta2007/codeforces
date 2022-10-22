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

fun gcd(a : Int, b: Int) : Int = if (a == 0) b else gcd(b % a, a)

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var (n, m) = Array(2) { getInt() }
        var a = Array(n) { getInt() }
        var b = Array(m) { getInt() }

        var gcd = 0
        for (i in b)
            gcd = gcd(gcd, abs(i))

        var sumOdd = 0L
        var sumEven = 0L
        for (i in 0 until gcd) {
            var sum = 0L
            var minabs = abs(a[i])
            var cnt = 0

            for (j in i until n step gcd) {
                sum += abs(a[j])
                minabs = min(minabs, abs(a[j]))
                if (a[j] <= 0)
                    cnt++
            }

            if (cnt % 2 == 0) {
                sumEven += sum
                sumOdd += sum - 2 * minabs
            } else {
                sumOdd += sum
                sumEven += sum - 2 * minabs
            }
        }

        println(max(sumOdd, sumEven))
    }
}