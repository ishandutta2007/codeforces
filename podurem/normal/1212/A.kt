private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n, k) = readInts()
    while (k > 0) {
        if (n % 10 == 0) {
            n /= 10
        } else {
            n--
        }
        k--
    }
    println(n)
}