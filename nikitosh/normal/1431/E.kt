import java.util.Collections
import kotlin.math.min
import kotlin.math.abs

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main(args: Array<String>) {
    var t = readInt()
    for (tt in 0 until t) {
        var n = readInt()
        var a = readInts()
        var b = readInts()
        var ans = 0
        var ind = -1
        for (i in 0 until n) {
            var cur = (1e9).toInt()
            for (j in 0 until i) {
                cur = min(cur, abs(b[j] - a[n - i + j]))
            }
            var k = n - i
            for (j in 0 until k)
                cur = min(cur, abs(a[j] - b[n - k + j]))
            if (cur > ans) {
                ans = cur
                ind = i
            }
        }
        val arr = IntArray(n) {it + 1}
        val list = arr.toList()
        Collections.rotate(list, -ind)
        println(list.toIntArray().joinToString(" "))
    }
}