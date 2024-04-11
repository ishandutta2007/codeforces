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
        var x = readLongs()

        var n = x[0]
        var k1 = x[1]
        var k2 = x[2]

        k2 = Math.min(k2-k1, k1)

        var s = readLn() + "0"
        var len = 0
        var ans = 0L
        for (i in 0 until s.length)
            if (s[i] == '1')
                len++
            else {
                var ceil = (len + 1) / 2
                var floor = len / 2
                ans += ceil * k1 + floor * k2
                len = 0
            }

        println(ans)
    }
}