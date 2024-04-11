private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (N, K) = readInts()
    val sum = 1 + K + K * K + K * K * K
    val mult = N / sum
    outputLn("${mult} ${mult * K} ${mult * K * K} ${mult * K * K * K}")
}

fun main() {
    val T = readInt()
    for (i in 1..T) go()
    println(OUTPUT_LINES.joinToString("\n"))
}