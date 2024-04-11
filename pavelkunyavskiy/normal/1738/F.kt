import java.util.TreeSet

class DSU(n: Int) {
    val p = IntArray(n) { it }
    fun get(x: Int) : Int = when {
        p[x] == x -> x
        else -> get(p[x]).also { p[x] = it }
    }
    fun join(a:Int, b: Int) {
        p[get(a)] = get(b)
    }
}

fun query(x:Int) : Int {
    println("? ${x+1}")
    System.out.flush()
    return readInt() - 1
}

fun answer(x: List<Int>) {
    println("! ${x.joinToString(" ")}")
    System.out.flush()
}

private fun solve() {
    val n = readInt()
    val d = readInts()
    val t = TreeSet<Int>(compareBy({ d[it] }, { it })).apply { addAll(0 until n) }
    val dsu = DSU(n)
    while (!t.isEmpty()) {
        val x = t.last()
        t.remove(x)
        for (i in 0 until d[x]) {
            val q = query(x)
            dsu.join(x, q)
            if (!t.remove(q)) {
                break
            }
        }
    }
    answer((0 until n).map { dsu.get(it) + 1 })
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