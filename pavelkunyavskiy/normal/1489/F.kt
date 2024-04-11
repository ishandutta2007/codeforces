fun main() {
    val (n, m, k) = readInts()
    val a = readInts()
    var sum = 0
    var ptr = 0
    val to = IntArray(n)
    for (i in 0 until n) {
        while (ptr < a.size && sum + a[ptr] <= k) {
            sum += a[ptr++]
        }
        sum -= a[i]
        to[i] = ptr
    }
    val dp = IntArray(n + 1)
    for (i in n-1 downTo 0) {
        dp[i] = dp[to[i]] + 1
    }
    print(n - dp.indexOfFirst { it <= m })
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }