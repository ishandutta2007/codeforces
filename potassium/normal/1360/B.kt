import java.util.*
import java.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var a = readInts().toIntArray()

        a.sort()

        var ans = Integer.MAX_VALUE;
        for (i in 0..n-2)
            ans = Math.min(ans, a[i + 1] - a[i])

        println(ans)
    }
}