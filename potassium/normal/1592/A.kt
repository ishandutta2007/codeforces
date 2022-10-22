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
    var t = getInt()
    var ans = Array(t) { 0 }
    for (i in 0 until t) {
        var (n,h) = Array(2) { getInt() }
        var a = MutableList(n) { getInt() }

        a.sortDescending()

        var sum = a[0] + a[1]
        var take = h / sum
        ans[i] = take * 2
        h -= take * sum

        if (h > 0) { ans[i]++; h -= a[0] }
        if (h > 0) ans[i]++
    }

    println(ans.joinToString("\n"))
}