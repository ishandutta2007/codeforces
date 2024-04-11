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
    var a = Array(n) { Array(m) { getInt() } }

    var b = Array(n) { Array(m) { 0 } }
    var op = mutableListOf<Array<Int>>()
    for (i in 0 until n - 1)
        for (j in 0 until m - 1)
            if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i + 1][j] == 1 && a[i + 1][j + 1] == 1) {
                op.add(arrayOf( i + 1, j + 1 ))
                b[i][j] = 1
                b[i][j + 1] = 1
                b[i + 1][j] = 1
                b[i + 1][j + 1] = 1
            }

    var eq = true
    for (i in 0 until n)
        for (j in 0 until m)
            if (a[i][j] != b[i][j])
                eq = false

    if (eq) {
        println(op.size)
        println(op.map{ it.joinToString(" ") }.joinToString("\n"))
    }
    else {
        println(-1)
    }
}