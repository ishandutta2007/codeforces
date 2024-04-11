private fun solve() {
    var (x, y) = readLongs()
    var ans = 0L
    while (y > 0) {
        ans += y % x
        y /= x
        x = 10
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