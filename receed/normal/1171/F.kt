private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    val t = readInt()
    for (z in 1..t) {
        val n = readInt()
        var a = (0..n-1).map { readInts() + it }.toTypedArray()
        a.sortBy() {it[0]}
        var mx = 0
        var b = Array(n) {2}
        var f = false
        for (i in 0..n-2) {
            mx = maxOf(mx, a[i][1])
            b[a[i][2]] = 1
            if (mx < a[i + 1][0]) {
                f = true
                break
            }
        }
        println(if (f) b.joinToString(" ") else -1)
    }
}