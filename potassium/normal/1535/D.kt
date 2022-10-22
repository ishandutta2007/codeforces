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
    val k = getInt()
    val FULL = 1 shl k

    fun toState(ch : Char) : Int = if (ch == '?') 3 else ch - '0' + 1

    var state = MutableList(FULL) { -1 }
    for ((idx, ch) in getInput().reversed().withIndex())
        state[idx + 1] = toState(ch)

    var dp = MutableList(FULL * 2) { 1 }
    fun calc(i : Int) {
        dp[i] = 0
        if (state[i] and 1 > 0) dp[i] += dp[(i shl 1) + 1]
        if (state[i] and 2 > 0) dp[i] += dp[i shl 1]
    }
    for (i in FULL - 1 downTo 1)
        calc(i)

    var q = getInt()
    while (q-- > 0) {
        var p = FULL - getInt()
        state[p] = toState(getInput()[0])
        while (p > 0) {
            calc(p);
            p = p shr 1
        }
        println(dp[1])
    }
}