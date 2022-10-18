import java.lang.Integer.max
import java.lang.Integer.min
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, k, x) = readInts()
    val a = readInts()

    var lo = -1L
    var hi = 12345678900000L
    while (hi-lo > 1) {
        val bnd = (lo+hi)/2
        var del = 0
        var i = 0
        while (i < n) {
            val Q = PriorityQueue<Int>(Collections.reverseOrder())
            var sum = 0L
            while (i < n && Q.size < x) {
                Q.add(a[i])
                sum += a[i]
                i += 1
            }
            while (sum > bnd) {
                sum -= Q.poll()
                del += 1
                if (i < n) {
                    Q.add(a[i])
                    sum += a[i]
                    i += 1
                }
            }
        }

        if (del <= k) {
            hi = bnd
        } else {
            lo = bnd
        }
    }
    println(hi)
}