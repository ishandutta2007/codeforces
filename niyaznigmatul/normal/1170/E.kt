import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val a = readInts().toIntArray()
    for (i in 1 until a.size) {
        a[i] += a[i - 1]
    }
    val q = readInt()
    for (day in 1..q) {
        val wList = readInts().drop(1).toMutableList()
        wList.add(m + 1)
        var last = 0
        var cur = 0
        for (x in wList) {
            val have = x - last - 1
            last = x
            var left = cur - 1
            var right = n
            val fromLeft = if (cur == 0) 0 else a[cur - 1]
            while (left < right - 1) {
                val mid = (left + right) shr 1
                if (a[mid] - fromLeft <= have) {
                    left = mid
                } else {
                    right = mid
                }
            }
            cur = left + 1
        }
        println(if (cur == n) "YES" else "NO")
    }
}