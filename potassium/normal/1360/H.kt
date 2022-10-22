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
        var nm = readInts()
        var n = nm[0]
        var m = nm[1]

        var rank = (1L.shl(m) - n - 1) / 2

        var s = arrayOfNulls<String>(n)
        for (i in 0 until n)
            s[i] = readLn()

        var v = Array<Long>(n) { it -> 0L }
        for (i in 0 until n) {
            var now = 0L
            for (j in 0 until m) {
                now = now.shl(1)
                if (s[i]!![j] == '1')
                    now++
            }
            v[i] = now
        }

        var l = 0L
        var r = 1L.shl(m)

        while (r >= l) {
            var mid = (l + r) / 2

            var count = mid
            for (i in 0 until n)
                if (v[i] < mid)
                    count--

            if (count <= rank) {
                l = mid + 1
            } else {
                r = mid - 1
            }
        }

        var ans = StringBuilder(m)
        for (i in 0 until m) {
            if (r.and(1L.shl(i)) > 0)
                ans.append('1')
            else
                ans.append('0')
        }

        ans = ans.reverse()
        println(ans)
    }
}