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
    var t = getInt()
    while (t-- > 0) {
        var (n,x,y) = readLine()!!.split(" ").map { it.toInt() }

        if (x > y)
            x = y.also { y = x }

        fun solve(l : Int, r : Int, x : Int) : Int {
            myAssert(l <= x && x <= r)
            var ld = x - l
            var rd = r - x
            return ld + rd + Math.min(ld, rd)
        }

        var ans = Int.MAX_VALUE
        for (l in x until y) {
            var cost = Math.max(solve(1, l, x), solve(l + 1, n, y))
            ans = Math.min(ans, cost)
        }

        println(ans)
    }
}