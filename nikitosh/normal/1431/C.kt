import kotlin.math.max

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
        var (n, k) = readInts()
        var a = readInts()
        var sums = IntArray(n + 1) {0}
        for (i in 0 until n) {
            sums[i + 1] = sums[i] + a[i]
        }
        var ans = 0
        for (i in 0 until n) {
            var l = (n - i) / k
            ans = max(ans, sums[i + l] - sums[i])
        } 
        println(ans)
    }
}