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

fun main() {
    var n = getInt()
    var a = Array(n + 2) { 0 }
    a[0] = -1
    a[1] = 200007
    for (i in 2 until n + 2)
        a[i] = getInt()

    var dp0 = Array(n + 2) { -1 }
    var dp1 = Array(n + 2) { -1 }
    dp1[1] = 0

    fun upd0(id: Int, nid: Int) {
        if (dp0[id] == -1 || a[dp0[id]] < a[nid])
            dp0[id] = nid
    }

    fun upd1(id: Int, nid: Int) {
        if (dp1[id] == -1 || a[dp1[id]] > a[nid])
            dp1[id] = nid
    }

    for (i in 2 until n + 2) {
        if (dp0[i - 1] != -1 && a[i] > a[i - 1]) upd0(i, dp0[i - 1])
        if (dp1[i - 1] != -1 && a[i] > a[dp1[i - 1]]) upd0(i, i - 1)
        if (dp1[i - 1] != -1 && a[i] < a[i - 1]) upd1(i, dp1[i - 1])
        if (dp0[i - 1] != -1 && a[i] < a[dp0[i - 1]]) upd1(i, i - 1)
    }

    if (dp0[n + 1] == -1 && dp1[n + 1] == -1) {
        println("NO")
        return
    }

    var ans = Array(n + 2) { -1 }
    run {
        var h = n + 1
        var cur = if (dp0[h] == -1) 1 else 0
        while (h >= 0) {
            var nxth = if (cur == 0) dp0[h] else dp1[h]
            for (i in nxth + 1 .. h)
                ans[i] = cur

            h = nxth
            cur = 1 - cur
        }
    }

    println("YES")
    println((2 until n + 2).map { ans[it] }.joinToString(" "))
}