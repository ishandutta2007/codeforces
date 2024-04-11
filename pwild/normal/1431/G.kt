import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, k) = readInts()
    val a = readInts().sorted()

    var s = Array<Int>(n+1) { 0 }
    for (i in 0 until n) {
        s[i+1] = s[i] + a[i]
    }

    val dp = Array(n+1) { Array(k+1) {-123456789} }
    dp[n][0] = 0

    for (i in n-1 downTo 0) {
        for (j in 0..k) {
            dp[i][j] = dp[i+1][j]
            for (t in 0..j) {
                if (i+2*t > n) break
                val add = s[i+2*t] + s[i] - 2*s[i+t]
                dp[i][j] = max(dp[i][j], add + dp[i+2*t][j-t])
            }
        }
    }
    println(dp[0][k])
}