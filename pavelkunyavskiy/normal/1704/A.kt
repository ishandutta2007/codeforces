private fun solve() : Boolean {
    readInts()
    val a = readLn()
    val b = readln()
    if (a.length < b.length) return false
    if (a.dropLast(b.length - 1).none { it == b[0] }) return false
    if (a.takeLast(b.length - 1) != b.drop(1)) return false
    return true
}

fun main() {
    repeat(readInt()) {
        println(if (solve()) "YES" else "NO")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }