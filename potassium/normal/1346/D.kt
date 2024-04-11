import java.lang.*
import java.util.*
import java.math.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var L1 = readInts()

        var n = L1[0]
        var m = L1[1]

        var u = IntArray(m)
        var v = IntArray(m)
        var w = IntArray(m)

        for (i in 0 until m) {
            var Ln = readInts()

            u[i] = Ln[0]
            v[i] = Ln[1]
            w[i] = Ln[2]
        }

        var ans = IntArray(n) { 0 }

        for (i in 0 until m) {
            ans[u[i] - 1] = Math.max(ans[u[i] - 1], w[i])
            ans[v[i] - 1] = Math.max(ans[v[i] - 1], w[i])
        }

        var isOK = true

        for (i in 0 until m) {
            if (Math.min(ans[u[i] - 1], ans[v[i] - 1]) != w[i])
                isOK = false
        }

        if (isOK) {
            println("YES")
            println(ans.joinToString(" "))
        }
        else
            println("NO")
    }
}