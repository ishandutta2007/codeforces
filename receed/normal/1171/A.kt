private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    val t = readLine()!!.toInt()
    for (i in 1..t) {
        val n = readInt()
        println(n / 2)
    }
}