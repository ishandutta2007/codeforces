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
    var (n, k) = Array(2) { getInt() }

    if (n < k || k < n.countOneBits()) {
        println("NO")
        return
    }

    var cnt = Array(30) { 0 }
    for (i in 0 until 30)
        if ((n shr i) % 2 == 1)
            cnt[i] = 1

    var b = n.countOneBits()
    while (b < k) {
        for (i in 1 until 30)
            if (cnt[i] > 0) {
                cnt[i]--
                cnt[i - 1] += 2
                b++
                break
            }
    }

    println("YES")
    println((0 until 30).map { c -> Array(cnt[c]) { 1 shl c }.joinToString(" ") }.joinToString(" ").trim())
}