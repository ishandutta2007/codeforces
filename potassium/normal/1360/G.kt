import java.lang.StringBuilder
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
        var x = readInts()
        var r = x[0]
        var c = x[1]
        var a = x[2]
        var b = x[3]

        if (r * a != c * b) {
            println("NO")
            continue
        }

        println("YES")

        var batch = r / b
        var ans = Array<Array<Integer>>(r) { Array<Integer>(c) { Integer(0) } }

        for (rr in 0 until r)
            for (cc in rr * a until rr * a + a)
                ans[rr][cc % c] = Integer(1)

        for (rr in 0 until r) {
            println(ans[rr].joinToString(""))
        }
    }
}