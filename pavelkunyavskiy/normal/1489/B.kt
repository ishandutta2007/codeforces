fun main() {
    val t = readInt()
    for (i in 1..t) {
        val (n, a, b) = readLongs()
        println((n % 2) * a + (n / 2) * Math.min(b, 2 * a))
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }