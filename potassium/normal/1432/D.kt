import java.util.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var (n, a, b) = readInts()

        var sb = StringBuilder()
        for (i in 0 until b)
            sb.append('a' + i)

        while (sb.length < n)
            sb.append(sb)

        println(sb.substring(0, n))
    }
}