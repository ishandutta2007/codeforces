import kotlin.math.min
import kotlin.math.max
import java.io.*
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var s = readLn()
    var n = s.length
    val pr = ArrayList<Int>()
    pr.add(0)
    for (i in 0 until n) {
        var k = 0
        if (s[i] == '0')
            k = 1
        pr.add(pr.last() + k)
    }
    for (k in 1 until n + 1) {
        var cur = 0
        var ans = 0
        while (cur < n) {
            var l = cur
            var r = n
            while (r - l > 1) {
                var m = (l + r) / 2
                var z = pr[m + 1] - pr[cur]
                var o = m + 1 - cur - z
                if (o <= k || z <= k)
                    l = m
                else
                    r = m
            }
            ans += 1
            cur = r
        }
        print(ans)
        print(" ")
    }
}