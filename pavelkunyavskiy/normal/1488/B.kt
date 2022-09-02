private fun solve() {
    val (n, k) = readLongs()
    val s = readLn()
    var cur = 0
    val prefixes = s.asSequence().map { when (it) {
        '(' -> 1
        ')' -> -1
        else -> throw RuntimeException()
    }}.map { cur += it; cur }.filter { it == 0 }.count()
    println(minOf(n / 2, minOf(k, n / 2 - prefixes) + prefixes))
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