import java.lang.AssertionError
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
    var (a,b,c) = readLine()!!.split(" ").map{ it.toInt() }
    var n = getInt()

    var ans = 0
    for (i in 0 until n) {
        var x = getInt()
        if (b < x && x < c)
            ans++
    }

    println(ans)
}