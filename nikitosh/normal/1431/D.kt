import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main(args: Array<String>) {
    var t = readInt()
    for (tt in 0 until t) {
        var n = readInt()
        var a = readInts()
        var b = a.mapIndexed {index, value -> Pair(value, index) }
        b = b.sortedWith(compareBy({ it.first }, { it.second }))
        var used = IntArray(n) {0}
        var ans = IntArray(n) {-1}
        var cur = 1
        for (i in 0 until n) {
            cur += b[i].first
            if (cur > n)
                break;
            ans[cur - 1] = b[i].second + 1
            used[b[i].second] = 1
        }
        var it = 0
        for (i in 0 until n) {
            if (used[i] == 0) {
                while (ans[it] != -1)
                    it += 1
                ans[it] = i + 1;
            }
        }
        println(ans.joinToString(" "))
    }
}