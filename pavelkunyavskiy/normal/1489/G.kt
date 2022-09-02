private class Dsu(n: Int) {
    val p: IntArray;

    init {
        this.p = (0 until n).map { it }.toIntArray()
    }

    fun get(pos: Int): Int {
        if (p[pos] == pos) {
            return pos
        }
        p[pos] = get(p[pos])
        return p[pos]
    }

    fun join(a: Int, b: Int): Boolean {
        val ar = get(a)
        val br = get(b)
        if (ar == br) {
            return false
        }
        p[ar] = br
        return true
    }
}

data class Edge(val a: Int, val b: Int, val w: Long)

fun main() {
    val (n, m) = readInts()
    val d = Dsu(n)
    val es = mutableListOf<Edge>()
    val a = readLongs()
    val min_id = a.indexOf(a.minOrNull()!!)
    for (i in 0 until n) {
        if (i != min_id) {
            es.add(Edge(min_id, i, a[min_id] + a[i]));
        }
    }
    for (i in 0 until m) {
        val (u, v, w) = readStrings();
        es.add(Edge(u.toInt() - 1, v.toInt() - 1, w.toLong()))
    }
    es.sortBy { it.w }
    println(es.filter { d.join(it.a, it.b) }.sumOf { it.w })
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }