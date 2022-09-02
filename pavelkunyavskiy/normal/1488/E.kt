import java.lang.Math.abs

private fun solve() {
    readInt()
    val a = readInts()
    val map = mutableMapOf<Int, Int>()
    val data = mutableListOf<Int>()
    val odd = mutableListOf<Int>()
    for (i in a.size - 1 downTo 0) {
        if (map.contains(a[i])) {
            data.add(map[a[i]]!!)
            odd.add(if (map[a[i]]!! == i + 1) 0 else 1)
        } else {
            map[a[i]] = i
        }
    }
    data.reverse()
    odd.reverse()
    val dp = MutableList(a.size + 1) { Int.MAX_VALUE }

    val ans = data.zip(odd).map {
        val pos = -dp.binarySearch(-it.first) - 1
        dp[pos] = -it.first
        2 * pos + it.second + 2
    }.maxOrNull()
    println(if (ans == null) 1 else ans)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }