import kotlin.math.*

private fun solve() {
    val (n, _) = readInts()
    val a = readInts().sorted().let { it + (it[0] + n) }.asSequence()
        .zipWithNext()
        .map { it.second - it.first - 1 }
        .sortedDescending()
        //.also { println(it.toList()) }
        .mapIndexed { i, v -> max(0, if (v == 4 * i + 1) 1 else (v - (4 * i + 1))).toLong() }
        //.also { println(it.toList()) }
    println(n - a.sum())
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