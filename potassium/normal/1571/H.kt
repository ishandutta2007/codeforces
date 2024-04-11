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

fun binpow(b : Long, p : Long, mod : Long) : Long {
    var bc = b
    var pc = p
    var ans = 1L
    while (pc > 0) {
        if ((pc and 1) > 0) ans = ans * bc % mod
        bc = bc * bc % mod
        pc /= 2
    }
    return ans
}

fun main() {
    var (n,a,b) = Array(3) { getInt() }

    val NUM = 1000000L
    val DEN = binpow(NUM, MOD998 - 2, MOD998)

    val OFFSET = 500
    var P_H = Array(1000) { 0 }
    var P_V = Array(1000) { 0 }
    var P_PLUS = Array(1000) { 1L } // y + x
    var P_MINUS = Array(1000) { 1L } // y - x

    P_H[0 + OFFSET] = 1
    P_H[2 * b + OFFSET] = 1
    P_V[0 + OFFSET] = 1
    P_V[2 * a + OFFSET] = 1

    for (i in 0 until n) {
        var (x,y) = Array(2) { getInt() }
        var p = getLong()
        x *= 2
        y *= 2
        p = p * DEN % MOD998

        P_H[y + OFFSET] = 1
        P_V[x + OFFSET] = 1

        P_PLUS[y + x + OFFSET]  = P_PLUS[y + x + OFFSET]  * (1 - p) % MOD998
        P_MINUS[y - x + OFFSET] = P_MINUS[y - x + OFFSET] * (1 - p) % MOD998
    }

    for (i in 0 until 1000) {
        P_PLUS[i] = 1 - P_PLUS[i]
        if (P_PLUS[i] < 0) P_PLUS[i] += MOD998
        P_MINUS[i] = 1 - P_MINUS[i]
        if (P_MINUS[i] < 0) P_MINUS[i] += MOD998
    }

    var bal = 0L
    for (x in 0 .. 2 * a)
        for (y in 0 .. 2 * b) {
            var base = 0
            if (P_H[y + OFFSET] == 1) base += if (x == 0 || x == 2 * a) 1 else 2
            if (P_V[x + OFFSET] == 1) base += if (y == 0 || y == 2 * b) 1 else 2

            var p1 = P_PLUS[y + x + OFFSET]
            var p2 = P_MINUS[y - x + OFFSET]

            val isCorner = if (x == 0 || x == 2 * a || y == 0 || y == 2 * b) 1 else 0

            bal += base
            if (base == 0) bal += (1 - p1) * (1 - p2) % MOD998 * 2 % MOD998
            bal += p1 * (1 - p2) % MOD998 * (2 - isCorner) % MOD998
            bal += (1 - p1) * p2 % MOD998 * (2 - isCorner) % MOD998
            bal += p1 * p2 % MOD998 * (4 - isCorner - isCorner) % MOD998

            bal %= MOD998
        }

    bal *= binpow(2, MOD998 - 2, MOD998)
    bal %= MOD998

    bal -= (2 * a + 1) * (2 * b + 1)
    bal += 1
    bal %= MOD998
    bal += MOD998
    bal %= MOD998

    println(bal)
}