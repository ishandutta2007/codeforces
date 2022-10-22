import java.lang.AssertionError
import java.math.BigInteger
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
    var q = getInt()
    val s = getInput()

    val a = MutableList<Int>(n) { 0 }
    for (i in 0 until n)
        a[i] = s[i] - 'a' + 1

    for (i in 1 until n)
        a[i] += a[i - 1]

    while (q-- > 0) {
        var (l, r) = arrayOf(getInt(), getInt())
        l--
        r--

        println(a[r] - if (l == 0) 0 else a[l - 1])
    }
}