import java.lang.AssertionError
import java.lang.StringBuilder
import java.math.BigInteger
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
    println((0 until t).map {
        var (n,m) = Array(2) { getInt() }

        var a = Array(n) { StringBuilder(getInput()) }
        for (r in n - 1 downTo 0)
            for (c in 0 until m)
                if (a[r][c] == '*') {
                    var toR = r
                    while (toR + 1 < n && a[toR + 1][c] == '.') toR++

                    a[r][c] = '.'
                    a[toR][c] = '*';
                }

        a.joinToString("\n")
    }.joinToString("\n"))
}