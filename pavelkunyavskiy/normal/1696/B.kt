private fun solve() {
    readInt()
    val a = readInts()
    println(when {
        a.all { it == 0 } -> 0
        a.dropWhile { it == 0 }.dropLastWhile { it == 0 }.none { it == 0 } -> 1
        else -> 2
    })
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