import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (y, b, r) = readInts()
    var tr = min(r, min(y + 2, b + 1))
    println(tr * 3 - 3)
}