import kotlin.math.*

private fun solve() : Long {
    val n = readInt()
    val types = readInts().toIntArray()
    val cost = readLongs().toLongArray()
    val zs = (0 until n).filter { types[it] == 0 }.map { cost[it] }.sortedDescending()
    val os = (0 until n).filter { types[it] == 1 }.map { cost[it] }.sortedDescending()
    val c = min(zs.size, os.size)
    return when {
        zs.size == os.size -> cost.sum() * 2 - cost.minOrNull()!!
        else -> zs.subList(0, c).sum() * 2 + zs.subList(c, zs.size).sum() + os.subList(0, c).sum() * 2 + os.subList(c, os.size).sum()
    }
}

fun main() {
    repeat(readInt()) {
        println(solve())
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }