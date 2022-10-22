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
    var n = getInt()
    var a = Array(n) { getInt() }

    var cnt = Array(150007) { 0 }
    for (i in a)
        cnt[i]++

    var ans = 0
    for (i in 1 .. 150001) {
        for (j in i - 1 .. i + 1) {
            if (cnt[j] > 0) {
                cnt[j]--
                ans++
                break
            }
        }
    }

    println(ans)
}