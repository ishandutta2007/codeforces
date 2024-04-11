import java.lang.*
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
        var x = readLongs();
        var n = x[0]
        var k = x[1]

        var sum = 1 + k + k * k + k * k * k
        var ans = LongArray(4)
        ans[0] = n / sum
        for (i in 1..3)
            ans[i] = ans[i - 1] * k

        println(ans.joinToString(" "))
    }
}