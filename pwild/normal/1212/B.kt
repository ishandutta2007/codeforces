private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val s = readLn()

    val twoGrams = (0 until n-1).map { s.substring(it,it+2)}
    val frequencies = twoGrams.groupingBy { it }.eachCount()

    println(frequencies.maxBy { it.value }?.key)
}