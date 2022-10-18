import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n,target) = readInts()
    var A: Array<Pair<Int,Int>> = Array<Pair<Int,Int>>(n) { Pair(0,0) }
    var eaten = 0L
    var cost = 0L
    for (i in 0 until n) {
        val (a,b,c) = readInts()
        eaten += a
        cost += a * 1L * c
        A[i] = Pair(c,b-a)
    }
    A.sortBy { it.first }

    if (eaten > target) {
        println(-1)
        return
    }

    for (i in 0 until n) {
        val eat = min(target-eaten, A[i].second + 0L)
        eaten += eat
        cost += eat * A[i].first
    }

    if (eaten < target) {
        cost = -1
    }
    println(cost)
}