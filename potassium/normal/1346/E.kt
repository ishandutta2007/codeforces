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
    var L1 = readInts()

    var n = L1[0]
    var m = L1[1]
    var k = L1[2]

    var dp = IntArray(n) { 1000000000 }
    dp[k - 1] = 0

    for (i in 0 until m) {
        var L = readInts()

        var x = L[0] - 1
        var y = L[1] - 1

        var oldDpx = dp[x]
        var oldDpy = dp[y]

        dp[x] = Math.min(oldDpx + 1, oldDpy)
        dp[y] = Math.min(oldDpy + 1, oldDpx)
    }

    for (i in 0 until n)
        if (dp[i] >= 1000000000)
            dp[i] = -1

    println(dp.joinToString(" "))
}