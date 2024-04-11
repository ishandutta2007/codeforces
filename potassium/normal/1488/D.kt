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
    val TWO = 2.toBigInteger()

    var t = getInt()
    while (t-- > 0) {
        var nl = getLong()
        var n = nl.toBigInteger()
        var s = getLong().toBigInteger()

        var l = (s + n - BigInteger.ONE) / n
        var r = s
        while (r > l) {
            var mid = (l + r + BigInteger.ONE) / TWO
            var midv = mid

            var sum = BigInteger.ZERO
            for (i in 0 until nl) {
                if (midv == BigInteger.ONE) {
                    sum += (nl - i).toBigInteger()
                    break
                }
                sum += midv
                midv = (midv + BigInteger.ONE) / TWO
            }

            if (sum <= s) {
                l = mid
            }
            else {
                r = mid.minus(BigInteger.ONE)
            }
        }

        println(l)
    }
}