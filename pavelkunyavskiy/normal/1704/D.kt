private fun solve() {
    val (n, m) = readInts()
    val a = LongArray(n) { readInts().withIndex().sumOf { (index, v) -> (index.toLong() + 1) * v }}
    val x = a.indices.maxByOrNull { a[it] }!!
    println("${x+1} ${a[x] - a.minOrNull()!!}")
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