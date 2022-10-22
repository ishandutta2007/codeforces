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
        var n = getInt()
        var a = Array(n) { getInt() }

        var ans = 0
        var l = n - 1
        while (l > 0) {
            while (l > 0 && a[l - 1] == a[n - 1])
                l--
            if (l > 0) {
                l = max(0, 2 * l - n)
                ans++
            }
        }
        println(ans)
    }
}