private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val (n, k) = readInts()
        val n1 = n / (1 + k + k * k + k * k * k)
        val res = arrayOf(n1, k * n1, k * k * n1, k * k * k * n1)
        println(res.map { it.toString() }.joinToString(" "))
    }
}