
private fun solve(test: Int) {
    val (x0, n) = readLongs()
    var m = n / 4 * 4
    var ans = x0
    while (m < n) {
        m += 1
        if (ans % 2 == 0L) {
            ans -= m
        } else {
            ans += m
        }
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