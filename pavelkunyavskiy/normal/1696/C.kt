private fun process(a: IntArray, m: Int) = buildList<Pair<Int, Long>> {
    for (x_ in a) {
        var c = 1
        var x = x_
        while (x % m == 0) {
            x /= m
            c *= m
        }
        if (!isEmpty() && last().first == x) {
            set(size - 1, x to last().second + c)
        } else {
            add(x to c.toLong())
        }
    }
}

private fun solve() {
    val (_, m) = readInts()
    val a = readInts()
    readInt()
    val b = readInts()
    println(if (process(a.toIntArray(), m) == process(b.toIntArray(), m)) "Yes"  else "No")
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