val g = IntArray(500)
private fun grundy(x: Int) : Int {
   return g.getOrNull(x) ?: g[(x - 200) % 34 + 200]
}
private fun solve() : Boolean {
    readInt()
    val s = readLn()
    if (s.count { it == 'R' } > s.count { it == 'B' }) return true
    if (s.count { it == 'R' } < s.count { it == 'B' }) return false
    val a = mutableListOf<Int>()
    var l = 1
    for ((x, y) in s.zipWithNext()) {
        if (x == y) {
            a.add(l)
            l = 1
        } else {
            l++
        }
    }
    a.add(l)
    return a.map { grundy(it) }.reduce(Int::xor) != 0
}

fun main() {
    for (i in g.indices) {
        val t = (2 ..i).map { g[it - 2] xor g[i - it] }.distinct().sorted()
        while (g[i] == t.getOrNull(g[i])) g[i]++
    }
    require(g.drop(200).dropLast(34) == g.drop(234))



    repeat(readInt()) {
        println(if (solve()) "Alice" else "Bob")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }