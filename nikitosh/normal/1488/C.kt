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
        var (n, x, y) = readInts()
        var i = min(x, y)
        var j = max(x, y)
        var ans = 3 * n
        for (k in i until j) {
            ans = min(ans, max(get(k, i), get(n - k, j - k)))
        }
        println(ans)
    }
}