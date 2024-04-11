import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, m, k) = readInts()

    val inf = 123456789
    var dp = Array<Int>(n) { inf }
    dp[k-1] = 0

    repeat(m) {
        val (aa,bb) = readInts()
        val a = aa-1
        val b = bb-1

        val dpa = min(dp[a]+1, dp[b])
        val dpb = min(dp[b]+1, dp[a])
        dp[a] = dpa
        dp[b] = dpb
    }

    for (i in dp.indices) {
        if (dp[i] >= inf) dp[i] = -1
    }
    println(dp.joinToString(" ") { it.toString() })
}