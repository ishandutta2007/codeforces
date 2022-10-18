private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val a = readInts().sorted()
        val b = readInts().sorted()
        val res = a[1] == b[1] && a[0]+b[0] == a[1]
        println(if (res) "Yes" else "No")
    }
}