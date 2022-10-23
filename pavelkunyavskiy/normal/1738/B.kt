private fun solve() : Boolean {
    val (n, k) = readInts()
    val a = readLongs()
    val ds = a.zipWithNext { x, y -> y - x }
    if (ds.asSequence().zipWithNext().any { it.first > it.second }) return false
    if (ds.isEmpty()) return true
    return a[0] <= (n - k + 1) * ds.first()
}

fun main() {
    repeat(readInt()) {
        println(if (solve()) "Yes" else "No")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }