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
        var n = x[0]
        var m = x[1]

        var s = arrayOfNulls<String>(n)
        for (i in 0 until n)
            s[i] = readLn()

        if (n == 1 || m == 1) {
            println(s[0])
            continue
        }

        var loc = -1
        for (i in 1 until n) {
            for (j in 0 until m)
                if (s[i]!![j] != s[0]!![j]) {
                    loc = j
                    break
                }
        }

        if (loc == -1) {
            println(s[0])
        } else {
            var ans = StringBuilder(s[0])

            var hasAns = false
            for (c in 'a' .. 'z') {
                ans[loc] = c
                var isFirst = true
                for (j in 0 until n) {
                    if (s[j]!![loc] != c && isFirst) {
                        isFirst = false
                        for (k in loc + 1 until m)
                            ans[k] = s[j]!![k]
                    }
                }

                var isOK = true
                for (j in 0 until n) {
                    var diff = 0
                    for (k in 0 until m)
                        if (s[j]!![k] != ans[k])
                            diff++

                    if (diff > 1)
                        isOK = false
                }

                if (isOK) {
                    println(ans)
                    hasAns = true
                    break
                }
            }

            if (!hasAns)
                println(-1)
        }
    }
}