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
    while (t-- > 0) {
        var s = getInput()

        if (s.indexOfFirst { it.equals('1') } == -1) {
            println(0)
            continue
        }

        var f = s.indexOfFirst { it.equals('1') }
        var l = s.indexOfLast { it.equals('1') }

        var ans = 0
        for (i in f .. l)
            ans += if (s[i] == '0') 1 else 0

        println(ans)
    }
}