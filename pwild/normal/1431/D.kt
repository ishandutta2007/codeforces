import java.lang.Integer.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val n = readInt()
        val a = readInts()
        var b = a.zip(1..n).sortedBy { it.first }
        val res = Array<Int>(n) { 0 }
        var c = 0
        for (k in res.indices) {
           val p = b.findLast { it.first <= c }
            if (p == null) {
                res[k] = b[b.size-1].second
                b = b.subList(0,b.size-1)
                c += 1
            } else {
                res[k] = p.second
                b = b.filter { it != p }
                c = 1
            }
        }
        println(res.joinToString(" ") { it.toString() })
    }
}