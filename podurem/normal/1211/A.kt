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
    var cur = -1
    var ind1 = -1
    var ind2 = -1
    var ind3 = -1
    for (i in 0 until 3) {
        var curind = -1
        for (j in 0 until A.size) {
            if (j + 1 != ind1 && j + 1 != ind2 && j + 1 != ind3 && A[j] > cur && (curind == -1 || A[curind] > A[j])) {
                curind = j
            }
        }
        if (curind == -1) {
            println("-1 -1 -1")
            return
        }
        when (i) {
            0 -> ind1 = curind + 1
            1 -> ind2 = curind + 1
            2 -> ind3 = curind + 1
        }
        cur = A[curind]
    }
    println("$ind1 $ind2 $ind3")
}