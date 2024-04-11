import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val (n, a, b) = readInts()
        val s = readLn()
        val v = s.split("0").map { it.length }

        var res = 0
        for (c in v) {
            if (c%2 == 1) res += a
            res += (c/2) * min(b,2*a)
        }
        println(res)
    }
}