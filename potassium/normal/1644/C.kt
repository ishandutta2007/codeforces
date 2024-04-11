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
    var t = getInt()
    while (t-- > 0) {
        var (n,x) = Array(2) { getInt() }
        var a = Array(n + 1) { if (it == 0) 0 else getInt() }
        var ps = Array(n + 1) { a[it] }
        for (i in 1 .. n)
            ps[i] += ps[i - 1]

        var best = Array(n + 1) { (-2e9).toInt() }
        best[0] = 0
        for (i in 1 .. n)
            for (j in 0 until i)
                best[i - j] = max(best[i - j], ps[i] - ps[j])

        println((0 .. n).map { k ->
            best.mapIndexed { index, i -> i + min(index, k) * x }.maxOf { it }
        }.joinToString(" "))
    }
}