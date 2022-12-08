private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var n = readInt()
    var A = readInts()
    var mx = A.max()!!
    var ind = -1
    for (i in 0 until A.size) {
        if (A[i] == mx) {
            ind = i
        }
    }
    if (mx == 0) {
        println(0)
    } else {
        println((mx - 1).toLong() * n + (ind + 1))
    }
}