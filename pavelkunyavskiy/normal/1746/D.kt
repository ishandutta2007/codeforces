

private fun solve() {
    val (n, k) = readInts()
    val g = run {
        val gg = List(n) { mutableListOf<Int>() }
        readInts().forEachIndexed { index, it ->
            gg[it - 1].add(index + 1)
        }
        gg.map { it.toIntArray() }
    }
    val s = readLongs().toLongArray()
    fun dfs(v:Int, k:Int) : Pair<Long, Long> {
        if (g[v].isEmpty()) return s[v] * k to s[v]
        val c = g[v].map { dfs(it, k / g[v].size) }.sortedByDescending { it.second }
        return s[v] * k + c.sumOf { it.first } + c.subList(0, k % c.size).sumOf { it.second } to s[v] + c[k % c.size].second
    }

    println(dfs(0, k).first)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }