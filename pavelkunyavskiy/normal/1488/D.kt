import java.lang.Math.abs

private fun solve() {
    val (n, s) = readLongs()
    var l = 1L
    var r = s + 1

    fun count(n:Long, last:Long):Long {
        var tot = 0L
        var cnt = 0L
        var cur = last
        while (cnt < n && cur > 1) {
            tot += cur
            cnt += 1
            cur = (cur + 1) / 2
        }
        return tot + n - cnt
    }
    while (r - l > 1) {
        val m = (l + r) / 2
        if (count(n, m) <= s) {
            l = m
        } else {
            r = m
        }
    }
    println(l)
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