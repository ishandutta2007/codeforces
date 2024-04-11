import kotlin.math.max

private fun solve(test: Int) {
    val n = readInt()
    val a = readInts().sorted().toIntArray()
    var ans = a[0]
    for (i in 1 until n) {
        ans = max(ans, a[i] - a[i - 1])
    }
    println(ans)
}

fun main() {
    val t = readInt()
    repeat(t) { solve(it) }
}


private fun readInts() = readWords().map { it.toInt() }
private fun readLongs() = readWords().map { it.toLong() }
private fun readWords() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readLn() = readLine()!!