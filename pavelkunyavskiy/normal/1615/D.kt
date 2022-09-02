private fun solve() {
    val (n, m) = readInts()
    val g = List(n) { mutableListOf<Pair<Int, Int>>() }
    repeat(n - 1) {
        val (a, b, w) = readInts()
        g[a - 1].add(b - 1 to w)
        g[b - 1].add(a - 1 to w)
    }
    val p = IntArray(n)
    val pe = IntArray(n);
    val comp = IntArray(n)
    val c = IntArray(n)
    var comps = 1
    fun dfs(v: Int, pp: Int, cc: Int) {
        c[v] = cc
        for ((u, w) in g[v]) {
            if (u != pp) {
                p[u] = v
                pe[u] = w
                if (w == -1) {
                    comp[u] = comps++
                    dfs(u, v, 0)
                } else {
                    comp[u] = comp[v]
                    dfs(u, v, cc xor (w.countOneBits() % 2))
                }
            }
        }
    }
    dfs(0, -1, 0)

    val gc = List(comps) { mutableListOf<Pair<Int, Int>>() }
    repeat(m) {
        val (a, b, r) = readInts()
        gc[comp[a - 1]].add(comp[b - 1] to (r xor c[a - 1] xor c[b - 1]))
        gc[comp[b - 1]].add(comp[a - 1] to (r xor c[a - 1] xor c[b - 1]))
    }


    val color = IntArray(comps) { -1 }

    fun dfs2(v: Int, c: Int): Boolean {
        if (color[v] == c) return true
        if (color[v] != -1) return false
        color[v] = c
        for ((u, w) in gc[v]) {
            if (!dfs2(u, w xor c)) return false
        }
        return true
    }

    for (i in 0 until comps) {
        if (color[i] == -1) {
            if (!dfs2(i, 0)) {
                println("NO")
                return
            }
        }
    }

    println("YES")
    println((1 until n).joinToString("\n") { v ->
        val par = p[v]
        val c = if (pe[v] != -1) pe[v] else (c[par] xor color[comp[v]] xor color[comp[par]])
        "${v + 1} ${par + 1} $c"
    })
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