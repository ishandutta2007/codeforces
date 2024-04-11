private fun solve() {
    val n = readInt()
    val b = readInts().toIntArray()

    val index = b.indices.groupBy({ b[it] }, { it + 1 })

    require(index[0] == null || index[n + 1] == null)

    val k = (1..n).count { b[it - 1] > it }

    val a = mutableListOf<Int>()

    tailrec fun go(bval: Int) {
        val x = index[bval]!!
        if (a.size + x.size == n) {
            a.addAll(x)
            return
        }
        val last = x.single { index[it] != null }
        a.addAll(x.filterNot { it == last })
        a.add(last)
        require((bval <= k) != (last <= k))
        go(last)
    }

    if (index[0] == null) {
        go(n + 1)
    } else {
        go(0)
    }



    println(k)
    println(a.joinToString(" "))
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