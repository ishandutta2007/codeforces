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
    var k = getInt()
    var s = getInput()
    var t = getInput()

    var a = Array(k) { (s[it] - 'a') + (t[it] - 'a') }
    for (i in 0 until k) {
        if (a[i] % 2 == 1) {
            myAssert(i != k - 1)
            a[i]--
            a[i + 1] += 26
        }
        a[i] /= 2
    }
    for (i in k - 1 downTo 0) {
        if (a[i] >= 26) {
            myAssert(i != 0)
            a[i] -= 26
            a[i - 1]++
        }
    }

    var ans = StringBuilder(k)
    for (i in 0 until k)
        ans.append('a' + a[i])

    println(ans)
}