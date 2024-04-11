import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val (n, m) = readInts()
        var edges = arrayListOf<List<Int>>()
        repeat(m) {
            edges.add(readInts())
        }
        edges.sortBy { -it[2] }

        var res = Array<Int>(n) { -1 }
        var ok = true
        for (e in edges) {
            val (aa, bb, c) = e
            val a = aa-1
            val b = bb-1
            if (res[a] == -1) res[a] = c
            if (res[b] == -1) res[b] = c

            if (min(res[a],res[b]) != c) ok = false
        }

        if (ok) {
            println("YES")
            println(res.joinToString(" ") { it.toString() })
        } else {
            println("NO")
        }
    }
}