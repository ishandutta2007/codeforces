import java.lang.AssertionError
import java.math.BigInteger
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
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}


class BIT(n : Int) {
    val N = n
    var a = MutableList(n + 1) { 0 }

    fun upd(id : Int, x : Int) {
        var i = id
        while (i <= N) {
            a[i] = Math.max(a[i], x)
            i += i and -i
        }
    }

    fun qry(id : Int) : Int {
        var ans = 0
        var i = id
        while (i > 0) {
            ans = Math.max(ans, a[i])
            i -= i and -i
        }
        return ans
    }
}

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var n = getInt()
        var a = MutableList(n) { getInt() }

        var rp = MutableList(n) { -1 }
        var pos = MutableList(n + 1) { Int.MAX_VALUE }
        for (i in n - 1 downTo 0) {
            rp[i] = pos[a[i]]
            pos[a[i]] = i
        }

        var p = mutableListOf<Int>()
        var w = mutableListOf<Int>()
        var adj = mutableListOf<Int>()
        for (i in 0 until n) {
            if (pos[a[i]] == i && rp[i] != Int.MAX_VALUE) {
                p.add(rp[i])
                w.add(2)
                adj.add(if (rp[i] == i + 1) 1 else 0)
            }
        }

        val len = p.size
        for (i in 0 until len)
            p[i] = n + 1 - p[i]

        var ans = 1

        var bit = BIT(n + 7)
        for (i in 0 until len) {
            var maxp = bit.qry(p[i])
            var cur = maxp + w[i]
            bit.upd(p[i], cur)
            ans = Math.max(ans, cur + 1 - adj[i])
        }

        println(ans)
    }
}