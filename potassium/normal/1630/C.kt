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
    var a = Array(n) { getInt() }

    var r = Array(n + 1) { -1 }
    for (i in 0 until n)
        r[a[i]] = max(r[a[i]], i)

    var to = Array(n) { r[a[it]] }
    for (i in 1 until n)
        to[i] = max(to[i], to[i - 1])

    var take = 1
    var now = 0
    while (now < n - 1) {
        now = max(to[now], now + 1)
        take++
    }
    println(n - take)
}