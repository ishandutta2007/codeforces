import java.lang.AssertionError
import java.lang.StringBuilder
import java.util.*
import kotlin.math.*

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


class BIT(var n : Int, var func : (Long, Long) -> Long, var e : Long) {
    var a = Array(n + 1) { e }

    fun upd(id : Int, v : Long) {
        var i = id
        while (i <= n) {
            a[i] = func(a[i], v)
            i += i and -i
        }
    }

    fun qry(id : Int) : Long {
        var ans = e
        var i = id
        while (i > 0) {
            ans = func(ans, a[i])
            i -= i and -i
        }
        return ans
    }
}

fun main() {
    val (n, m) = arrayOf(getInt(), getInt())

    class Attack(var a : Int, var b : Int, var i : Int)
    var atks = ArrayList<Attack>()
    for (i in 0 until n) {
        var k = getInt()
        var a = Array(k) { getInt() }
        var b = Array(k) { getInt() }
        for (j in 0 until k)
            if (b[j] >= m - i)
                atks.add(Attack(a[j], b[j], i))
    }
    atks.sortWith(compareBy({ it.b + it.i }, { -it.i }))

    var bit = BIT(m + 1, ::max, Long.MIN_VALUE)
    bit.upd(1, 0)
    for (atk in atks) {
        var cur = bit.qry(m + 1 - atk.b)
        bit.upd(m + 1 - atk.b, cur + atk.a)
    }

    println(bit.qry(m + 1))
}