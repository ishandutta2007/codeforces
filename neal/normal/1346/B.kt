private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

private val OUTPUT_LINES = mutableListOf<String>()
private fun outputLn(s: String) { OUTPUT_LINES += s }

fun go() {
    val (N, K1, K2) = readInts()
    val S = readLn()
    var previous = 0
    var answer = 0

    for (i in 0..N-1) {
        var current = 0

        if (S[i] == '1') {
            current = minOf(K1, K2 - previous)
            answer += current
        }

        previous = current
    }

    outputLn("${answer}")
}

fun main() {
    val T = readInt()
    for (i in 1..T) go()
    println(OUTPUT_LINES.joinToString("\n"))
}