import java.lang.*
import java.util.*
import java.math.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }


fun gcd(x : Int, y: Int) : Int {
    var a = Math.min(x, y)
    var b = Math.max(x, y)

    while (a != 0) {
        var t = b % a
        b = a
        a = t
    }

    return b
}


var k = 0
var n = 0
var p = IntArray(0)
var x = IntArray(0)
fun check(f : Int, d : Int) : Boolean {
    var mark = Array<Boolean>(n) { false }

    for (i in f until n)
        if ((x[i] - x[f]) % d == 0)
            mark[i] = true

    var firstUnmarked = x[0]
    var lastUnmarked = -1
    var GCD = 0
    for (i in 0 until n)
        if (!mark[i]) {
            if (lastUnmarked == -1) {
                firstUnmarked = x[i]
            } else {
                GCD = gcd(GCD, x[i] - x[lastUnmarked])
            }
            lastUnmarked = i
        }

    if (GCD == 0) {
        println("YES")
        println("${x[f]} ${d}")
        println("${firstUnmarked} ${d}")
        return true
    }

    var choose = -1
    for (i in p)
        if (GCD % i == 0)
            choose = i

    if (choose != -1) {
        println("YES")
        println("${x[f]} ${d}")
        println("${firstUnmarked} ${choose}")
        return true
    }

    return false
}

fun main() {
    var L1 = readInts()

    k = L1[0]
    n = L1[1]

    p = readInts().toIntArray()
    x = readInts().toIntArray()

    if (n == 2) {
        println("YES")
        println("${x[0]} ${p[0]}")
        println("${x[1]} ${p[0]}")
        return;
    }

    for (f in 0..1)
        for (s in f+1..2) {
            var d = x[s] - x[f]

            for (i in p)
                if (d % i == 0)
                    if (check(f, i))
                        return;
        }

    println("NO")
}