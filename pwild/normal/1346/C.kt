import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val (n, k, x, y) = readInts()
        val a = readInts().sorted()

        var s = 0L
        for (c in a) s += c

        var res = n*x

        for (i in n downTo 1) {
            if (s <= n*1L*k) res = min(res, (n-i)*x + y)
            if (a[i-1] <= k) res = min(res, (n-i)*x)
            s -= a[i-1]
        }
        println(res)
    }
}