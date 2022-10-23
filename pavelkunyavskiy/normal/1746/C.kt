private fun solve() {
    readInt()
    val a = readInts().map { it - 1 }
    val b = IntArray(a.size) { 0 }
    for ((index, i) in a.withIndex())
        b[i] = minOf(a.size, index + 2)
    println(b.joinToString(" "))
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