import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt()
    var arr = readLongs()
    var ans = 0.toLong()
    for (i in 0 until n) {
        if (arr[i] != 0.toLong()) {
            ans = max(ans, (arr[i] - 1) * n + i + 1)
        }
    }
    println(ans)
}