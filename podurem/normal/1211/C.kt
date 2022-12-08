import java.lang.Math.max
import java.lang.Math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var (n, k) = readInts()
    var A = ArrayList<Pair<Int, Int>>()
    var curK = 0
    var ans: Long = 0
    for (i in 0 until n) {
        var (a, b, c) = readInts()
        A.add(Pair(b - a, c))
        curK += a
        ans += a.toLong() * c
        if (curK > k) {
            println(-1)
            return
        }
    }
    A.sortBy { it.second }
    for (i in 0 until A.size) {
        var need = max(0, min(k - curK, A[i].first))
        curK += need
        ans += need.toLong() * A[i].second
    }
    when (curK) {
        k -> println(ans)
        else -> println(-1)
    }
}