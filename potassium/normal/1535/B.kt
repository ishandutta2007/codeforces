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

fun gcd(x : Int, y : Int) : Int = if (x == 0) y else gcd(y % x, x)

fun main() {
    var t = getInt()
    while (t-- > 0) {
        val n = getInt()
        val a = MutableList(n) { getInt() }

        a.sortWith { x, y -> (x % 2).compareTo(y % 2) }

        var ans = 0
        for (i in 0 until n)
            for (j in i + 1 until n)
                if (gcd(a[i], 2 * a[j]) > 1)
                    ans++

        println(ans)
    }
}