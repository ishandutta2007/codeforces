import kotlin.math.*

private fun solve() {
    val (_, x) = readInts()
    val a = readInts().toIntArray()
    var m = a[0]
    var M = a[0]
    var ans = 0
    for (v in a) {
        m = min(m, v)
        M = max(M, v)
        if (M - m > 2 * x) {
            ans += 1
            m = v
            M = v
        }
    }
    println(ans)
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