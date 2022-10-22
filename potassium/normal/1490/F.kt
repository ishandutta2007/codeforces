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
        var n = getInt()
        var a = MutableList(n) { getInt() }

        var m = TreeMap<Int, Int>()
        for (i in a)
            m[i] = m.getOrDefault(i, 0) + 1

        val num = m.size
        val v = m.map{ it.value }.toMutableList()
        v.sort()

        val ss = MutableList(num) { v[it] }
        for (i in num - 2 downTo 0)
            ss[i] += ss[i + 1]

        var ans = Int.MAX_VALUE
        for (i in 0 until num) {
            var cost = ss[0] - (num - i) * v[i]
            ans = Math.min(ans, cost)
        }

        println(ans)
    }
}