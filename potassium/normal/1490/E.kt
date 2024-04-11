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
    override fun compare(o1: Array<Long>, o2: Array<Long>): Int {
        for (i in o1.indices)
            if (o1[i] != o2[i])
                return if (o1[i] < o2[i]) -1 else 1
        return 0
    }
}

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var n = getInt()
        var a = MutableList(n) { arrayOf(getLong(), it.toLong()) }

        a.sortWith(comp())
        var ps = MutableList(n) { a[it][0] }
        for (i in 1 until n)
            ps[i] += ps[i - 1]

        var ans = 0
        for (i in 0 until n - 1)
            if (ps[i] < a[i + 1][0])
                ans = i + 1

        println(n - ans)
        var win = MutableList<Long>(0) { 0 }
        for (i in ans until n)
            win.add(a[i][1] + 1)

        println(win.sorted().joinToString(" "))
    }
}