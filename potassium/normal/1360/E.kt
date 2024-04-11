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
        var n = readInt()
        var s = arrayOfNulls<String>(n)

        for (i in 0 until n)
            s[i] = readLn()

        var ans = 1
        for (r in 0 until n - 1)
            for (c in 0 until n - 1)
                if (s[r]!![c] == '1' && s[r]!![c + 1] == '0' && s[r + 1]!![c] == '0')
                    ans = 0

        if (ans == 1) {
            println("YES")
        } else {
            println("NO")
        }
    }
}