private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts()

    var i = 0
    for (j in 1 until n) {
        if (a[j] >= a[i]) i = j
    }

    println(n*1L*(a[i]-1) + i + 1)
}