import java.lang.AssertionError
import java.lang.StringBuilder
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

fun main() {
    var n = getInt()
    var a = MutableList(n) { getInt() }
    var b = MutableList(n + 1) { getInt() }
    a.sort()
    b.sort()

    var pre = MutableList(n) { b[it] - a[it] }
    var suf = MutableList(n) { b[it + 1] - a[it] }
    for (i in 1 until n) pre[i] = maxOf(pre[i], pre[i - 1])
    for (i in n - 2 downTo 0) suf[i] = maxOf(suf[i], suf[i + 1])

    var q = getInt()
    var c = MutableList(q) { Pair(getInt(), it) }
    var ans = MutableList(q) { Integer.MIN_VALUE }
    c.sortWith { x, y -> if (x.first != y.first) x.first.compareTo(y.first) else x.second.compareTo(y.second) }

    var pos = 0
    for ((v, id) in c) {
        while (pos < n && a[pos] < v) pos++
        ans[id] = b[pos] - v
        if (pos > 0) ans[id] = maxOf(ans[id], pre[pos - 1])
        if (pos < n) ans[id] = maxOf(ans[id], suf[pos])
    }

    println(ans.joinToString(" "))
}