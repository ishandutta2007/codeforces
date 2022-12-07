private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    val nTest = readInt();
    repeat(nTest) {
        var (a, b, k) = readInts();
        println((k.toLong() + 1) / 2 * a - k.toLong() / 2 * b);
    }
}