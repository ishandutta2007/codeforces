import java.lang.Math.abs

private fun solve() {
    val (n, x_, y_) = readInts()
    val x = minOf(x_, y_)
    val y = maxOf(x_, y_)

    fun len(x: Int, l: Int, r: Int) = minOf(abs(x - l), abs(x - r)) + r - l

    println((1 until n).asSequence().map { maxOf(len(x, 1, it), len(y, it + 1, n))}.minOrNull()!!)
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