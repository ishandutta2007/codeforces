private fun solve() {
    val n = readInt()
    val a = readLn()
    val b = readLn()
    val diffs = a.indices.count { a[it] != b[it] }
    println(listOfNotNull(
        diffs.takeIf { a.count { it == '1'} == b.count { it == '1' } },
        (n - diffs).takeIf { a.count { it == '0'} + 1 == b.count { it == '1' } }
    ).minOrNull() ?: -1)
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