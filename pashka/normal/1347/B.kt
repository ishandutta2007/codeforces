private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

private fun solveTest() {
    var (a1, b1) = readInts()
    var (a2, b2) = readInts()
    if (a1 < b1) {
        var t = a1
        a1 = b1
        b1 = t
    }
    if (a2 < b2) {
        var t = a2
        a2 = b2
        b2 = t
    }
    if (a1 == a2 && b1 + b2 == a1) {
        println("Yes")
    } else {
        println("No")
    }
}

fun main(args: Array<String>) {
    var t = readInt()
    while (t-- > 0) {
        solveTest();
    }
}