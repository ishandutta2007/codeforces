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
    var cnt = Array(200007) { 0 }
    for (i in 0 until n)
        cnt[getInt()]++

    if (cnt.maxOf { it } >= 3) {
        println("NO")
        return
    }

    println("YES\n" +
            cnt.count { it >= 1 } + "\n" +
            (0 .. 200000).filter { cnt[it] >= 1 }.map { it }.joinToString(" ") + "\n" +
            cnt.count { it >= 2 } + "\n" +
            (200000 downTo 0).filter { cnt[it] >= 2 }.map { it }.joinToString(" ") + "\n"
    )
}