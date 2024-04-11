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
        var x = readInts();

        var a = x[0]
        var b = x[1]

        if (a > b) {
            var t = a
            a = b
            b = t
        }

        var sz = Math.max(2 * a, b);
        println(sz * sz)
    }
}