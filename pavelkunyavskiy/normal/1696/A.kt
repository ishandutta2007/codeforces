private fun solve() {
    val (_, z) = readInts()
    println(readInts().maxOf { it or z })
}

fun main() {
    repeat(readInt()) { solve () }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }