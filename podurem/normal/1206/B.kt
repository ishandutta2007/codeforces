private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val n = readInt()
    val A = readInts()
    var exist0 = false
    var ans: Long = 0
    var mul = 1
    for (i in 0 until n) {
        when {
            A[i] < 0 -> {
                ans += -A[i] - 1
                mul *= -1
            }
            A[i] == 0 -> {
                ans += 1
                exist0 = true
            }
            else -> {
                ans += A[i] - 1
            }
        }
    }
    if (mul == 1 || exist0) {
        println(ans)
    } else {
        println(ans + 2)
    }
}