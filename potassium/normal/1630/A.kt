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
    var t = getInt()
    while (t-- > 0) {
        var (n,k) = arrayOf(getInt(), getInt())

        if (k < n - 1) {
            var a = Array(n) { it }
            a[0] = k
            a[k] = 0

            for (i in 0 until n / 2)
                println("${a[i]} ${a[n - 1 - i]}")
        }
        else if (n == 4) {
            println(-1)
        }
        else
        {
            println("${n - 1} ${n - 2}")
            println("${n - 3} 1")
            println("0 2")
            for (i in 3 until n / 2)
                println("$i ${n - 1 - i}")
        }
    }
}