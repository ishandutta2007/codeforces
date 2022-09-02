private const val MOD = 998244353

private fun solve() : Int {
    val (n, m) = readInts()
    val a = readInts().toIntArray()
    val g = List(n) { ArrayList<Int>() }
    repeat(m) {
        val (a, b) = readInts().map { it - 1 }
        g[a].add(b)
    }
    val order = mutableListOf<Int>()
    val used = BooleanArray(n) { false }
    fun dfs(v: Int) {
        if (used[v]) return
        used[v] = true
        for (u in g[v]) dfs(u)
        order.add(v)
    }
    for (i in g.indices) dfs(i)

    val t = g.indices.single { g[it].size == 0 }
    repeat(n) {
        if (a.all { it == 0 }) return it
        for (i in order) {
            if (a[i] != 0) {
                a[i] -= 1
                for (j in g[i]) {
                    a[j] += 1
                }
            }
        }
    }
    for (i in order.reversed()) {
        for (j in g[i]) {
            a[j] = (a[j] + a[i]) % MOD
        }
    }
    return (n + a[t]) % MOD
}

fun main() {
    repeat(readInt()) {
        println(solve())
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }