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

class comp : Comparator<Array<Long>> {
    override fun compare(o1 : Array<Long>, o2: Array<Long>): Int {
        for (i in o1.indices)
            if (o1[i] != o2[i])
                return if (o1[i] < o2[i]) -1 else 1
        return 0
    }
}

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var (n, m) = arrayOf(getInt(), getInt())
        var a = MutableList(n) { arrayOf(getLong(), it.toLong()) }
        var q = MutableList(m) { arrayOf(getLong(), it.toLong()) }

        var ans = MutableList(m) { 0L }
        for (i in 1 until n)
            a[i][0] += a[i - 1][0]

        val sum = a[n - 1][0]
        val maxv = a.map{ it[0] }.maxOrNull()!!
        for (i in q) {
            var d = i[0] - maxv
            if (d <= 0 || sum <= 0) continue
            var need = (d + sum - 1) / sum

            i[0] -= need * sum
            ans[i[1].toInt()] += need * n
        }

        a.sortWith(comp())
        q.sortWith(comp())
        q.reverse()
        var cur = Long.MAX_VALUE
        for (i in q) {
            while (!a.isEmpty() && a.last()[0] >= i[0]) {
                cur = Math.min(cur, a.last()[1])
                a.removeLast()
            }

            if (cur == Long.MAX_VALUE)
                ans[i[1].toInt()] = -1
            else
                ans[i[1].toInt()] += cur
        }

        println(ans.joinToString(" "))
    }
}