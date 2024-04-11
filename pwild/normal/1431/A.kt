import java.lang.Long.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    val tc = readInt()
    repeat(tc) {
        val n = readInt()
        val a = readLongs()
        var res = 0L
        for (x in a) {
            res = max(res, a.filter { it >= x }.size * x)
        }
        println(res)
    }
}