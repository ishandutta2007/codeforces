import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val (n, k) = readInts()
        val p = readInts()
        var res = 0
        for (m in 1..n) {
            res = max(res, p.subList(n-m,n-m+m/k).sum())
        }
        println(res)
    }
}