import java.lang.Integer.max
import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val n = readInt()
        val a = readInts()
        val b = readInts()

        var k = -1
        var res = 0
        for (i in 0 until n) {
            var cur = 1234567
            for (j in 0 until n) {
                cur = min(cur, kotlin.math.abs(a[j] - b[(i + j) % n]))
            }
            if (cur > res) {
                res = cur
                k = i
            }
        }

        val ans = (k+1 .. n) + (1 .. k)
        println(ans.joinToString(" ") { it.toString() })

    }
}