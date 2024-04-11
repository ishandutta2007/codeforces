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
    var (n,m) = arrayOf(getInt(), getInt())
    var count = MutableList(m) { 0 }

    for (i in 0 until n) {
        var x = getInt()
        count[x % m]++
    }

    var can = MutableList(m + 1) { false }
    can[m] = true

    for (i in 0 until m) {
        var used = MutableList(m + 1) { false }
        for (j in 0 .. m) {
            if (used[j] || !can[j]) continue
            var cnt = count[i]
            var now = j
            while (cnt-- > 0) {
                now = (now + i) % m
                if (!can[now]) {
                    can[now] = true
                    used[now] = true
                }
                else {
                    break
                }
            }
        }
    }

    println(if (can[0]) "YES" else "NO")
}