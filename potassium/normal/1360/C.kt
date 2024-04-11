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

        var oddCount = 0
        var evenCount = 0
        var hasAdj = 0

        for (i in 0 until n - 1) {
            if (a[i + 1] - a[i] == 1)
                hasAdj = 1
        }

        for (i in 0 until n) {
            if (a[i] % 2 == 0)
                evenCount++
            else
                oddCount++
        }

        if (oddCount % 2 == 1 && hasAdj == 0) {
            println("NO")
        } else {
            println("YES")
        }
    }
}