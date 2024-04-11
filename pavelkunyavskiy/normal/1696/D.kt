import kotlin.math.*

private fun solve(a: IntArray) : Int {
    val pos = IntArray(a.maxOrNull()!! + 1) { -1 }
    for ((i, v) in a.withIndex()) pos[v] = i
    val prefixMax = a.runningReduce(::max)
    val prefixMin = a.runningReduce(::min)
    var ops = 0
    var curPos = a.size - 1
    while (curPos != 0) {
        ops++
        require(a[curPos] == prefixMin[curPos] || a[curPos] == prefixMax[curPos])
        curPos = pos[prefixMin[curPos] + prefixMax[curPos] - a[curPos]]
    }
    return ops
}

private fun solve() {
    readInt()
    val a = readInts().map { it - 1 }
    val pos0 = a.indexOf(0)
    println(solve(a.subList(0, pos0 + 1).toIntArray()) + solve(a.subList(pos0, a.size).reversed().toIntArray()))
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