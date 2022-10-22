import java.util.*
import java.math.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var x = readInts()

        var n = x[0]
        var k = x[1]

        var sqrtN = Math.sqrt( n.toDouble() ).toInt()

        var ans = Integer.MAX_VALUE
        for (i in 1..sqrtN + 7) {
            if (n % i == 0) {
                if (n / i <= k)
                    ans = min(ans, i)
                if (i <= k)
                    ans = min(ans, n / i)
            }
        }

        println(ans)
    }
}