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
    var a = Array<Int>(n) { getInt() }

    var id = Array<Int>(n) { it }
    id.sortByDescending { a[it] }

    var ans = 0
    for ((i, v) in id.withIndex()) {
        ans += i * a[v] + 1
    }

    println(ans)
    println(id.map { it + 1 }.joinToString(" "))
}