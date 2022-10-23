private fun solve() {
    val (n, k) = readInts()
    val a = readInts()
    println(if (a.any { it == 1 }) "YES" else "NO")
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