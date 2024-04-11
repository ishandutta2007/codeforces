import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n, k) = readInts()
    for (i in 0 until k) {
        if (n % 10 != 0) {
            n -= 1
        } else {
            n /= 10
        }
    }
    println(n)
}