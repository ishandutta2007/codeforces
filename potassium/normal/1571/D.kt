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
    var (n,m) = Array(2) { getInt() }
    var x = Array(n + 1) { 0 }
    var y = Array(n + 1) { 0 }
    var z = Array(n + 1) { Array(n + 1) { 0 } }

    var (myX, myY) = Array(2) { getInt() }
    for (i in 1 until m) {
        var (f,l) = Array(2) { getInt() }
        x[f]++
        y[l]++
        z[f][l]++
    }

    var ans = 1
    for (i in 1 .. n)
        for (j in 1 .. n) {
            if (i == j) continue
            var correct = (if (i == myX) 1 else 0) + (if (j == myY) 1 else 0)

            var lose = 0
            if (correct < 2) lose += z[i][j]
            if (correct < 1) lose += x[i] + y[j] - z[i][j] * 2

            ans = Math.max(ans, lose + 1)
        }

    println(ans)
}