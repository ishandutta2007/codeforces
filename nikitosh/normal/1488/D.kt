import kotlin.math.min
import kotlin.math.max
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun get(n: Int, k: Int): Int {
    return min(k - 1 + n - 1, n - k + n - 1)
} 
 
fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var (n, s) = readLongs()
        var l = (s + n - 1) / n
        var r = s + 1
        while (r - l > 1) {
            var m = (l + r) / 2
            var sum = 0L
            var cnt = 0L
            var cur = m
            while (cnt < n && cur != 1L) {
                sum += cur
                cnt++
                cur = (cur + 1) / 2
            }
            sum += n - cnt
            if (sum <= s)
                l = m
            else
                r = m
        }
        println(l)
    }
}