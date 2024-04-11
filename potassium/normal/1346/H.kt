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
    var L1 = readInts()

    var n = L1[0]
    var m = L1[1]

    var QL = IntArray(n)
    var QR = IntArray(n)

    for (i in 0 until n) {
        var L2 = readInts()

        QL[i] = L2[0]
        QR[i] = L2[1]
    }

    var D = Array<TreeSet<Int>>(2000000) { TreeSet<Int>() }

    for (i in 0 until m) {
        var L3 = readInts()

        var L = L3[0]
        var R = L3[1]

        D[L + R].add(R)
    }

    var ans = IntArray(n)
    for (i in 0 until n) {
        var x = D[QL[i] + QR[i]].floor(QR[i])
        var y = D[QL[i] + QR[i] - 2].floor(QR[i] - 2)
        var z = D[QL[i] + QR[i] + 2].floor(QR[i])
        if ((x == null && y == null) || (x == null && z == null)) {
            ans[i] = -1
        } else {
            var a = 0
            var b = 0
            var c = 0

            if (x == null)
                a = Integer.MAX_VALUE
            else
                a = QR[i] - x

            if (y == null)
                b = Integer.MAX_VALUE
            else
                b = 1 + QR[i] - 2 - y

            if (z == null)
                c = Integer.MAX_VALUE
            else
                c = 1 + QR[i] - z

            ans[i] = Math.max(Math.min(a, b), Math.min(a, c))
        }
    }

    println(ans.joinToString(" "))
}