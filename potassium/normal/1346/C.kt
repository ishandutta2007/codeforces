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
        var L1 = readLongs()

        var n = L1[0]
        var k = L1[1]
        var x = L1[2]
        var y = L1[3]

        var a = readLongs()
        a = a.sortedDescending()

        var thres = k * n
        var sum = 0L
        for (i in 0 until n)
            sum += a[i.toInt()]

        var ans1 = y
        var ans2 = 0L
        for (i in 0 until n) {
            if (sum > thres) {
                sum -= a[i.toInt()]
                ans1 += x
            }
            if (a[i.toInt()] > k) {
                ans2 += x
            }
        }

        println(Math.min(ans1, ans2))
    }
}