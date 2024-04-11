import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var (n, k) = readInts()
    var from = IntArray(n)
    var to = IntArray(n)
    var cost = IntArray(n)
    for (i in 0 until n) {
        var tmp = readInts()
        from[i] = tmp[0]
        to[i] = tmp[1]
        cost[i] = tmp[2]
    }

    var ans = 0.toLong()
    var sum = 0.toLong()
    for (i in 0 until n) {
        ans += cost[i].toLong() * from[i]
        sum += from[i]
    }

    if (sum > k) {
        println(-1)
        return
    }

    var order = ArrayList<Pair<Int, Int>>()
    for (i in 0 until n) {
        order.add(Pair(cost[i], i))
    }
    order.sortBy { it.first }

    for (i in 0 until n) {
        val ind = order[i].second
        if (k - sum >= to[ind] - from[ind]) {
            sum += to[ind] - from[ind]
            ans += (to[ind] - from[ind]).toLong() * cost[ind]
        } else {
            ans += (k - sum).toLong() * cost[ind]
            sum = k.toLong()
            break
        }
    }
    if (sum < k) {
        println(-1)
    } else {
        println(ans)
    }
}