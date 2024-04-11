import java.util.*

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun binpow(b : Long, p : Long, mod : Long) : Long {
    var pw = p
    var cur = b
    var ans = 1L
    while (pw > 0) {
        if ((pw and 1) > 0)
            ans = (ans * cur) % mod

        cur = (cur * cur) % mod
        pw = pw shr 1
    }
    return ans
}


fun main() {
    var n = Array<Int>(4) { getInt() }
    var a = Array<MutableList<Long>>(4) { MutableList<Long>(n[it]) { getLong() } }

    var m = Array<Int>(3) { 0 }
    var g = Array<Array<TreeSet<Int>>>(3) { Array<TreeSet<Int>>(n[it]) { TreeSet<Int>() } }

    for (i in 0 until 3) {
        m[i] = getInt()
        for (j in 0 until m[i]) {
            var (u, v) = arrayOf(getInt(), getInt())
            u--
            v--
            g[i][u].add(v)
        }
    }

    val IMP = 1_000_000_000_000L

    var dp = Array<MutableList<Long>>(4) { i -> MutableList<Long>(n[i]) { j -> a[i][j] } }
    for (i in 2 downTo 0) {
        var order = MutableList<Int>(n[i + 1]) { it }
        order.sortBy { dp[i + 1][it] }

        for (j in 0 until n[i]) {
            var add = IMP
            for (k in order) {
                if (!g[i][j].contains(k)) {
                    add = dp[i + 1][k]
                    break
                }
            }
            dp[i][j] += add
        }
    }

    var ans = Long.MAX_VALUE
    for (i in dp[0])
        ans = Math.min(ans, i)

    println(if (ans >= IMP) -1 else ans)
}