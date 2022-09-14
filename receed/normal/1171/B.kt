private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    val (y, b, r) = readInts()
    val m = minOf(y, b - 1, r - 2)
    println(m * 3 + 3)
}