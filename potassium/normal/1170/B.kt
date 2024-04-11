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
    var n = getInt()

    var max = -1
    var smax = -1
    var ans = 0
    while (n-- > 0) {
        var x = getInt()
        if (x < smax) ans++
        if (x > max) {
            smax = max
            max = x
        }
        else if (x > smax) {
            smax = x
        }
    }

    println(ans)
}