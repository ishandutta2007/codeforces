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
    val (n, m) = readInts()
    var myF = 0
    var myL = 0
    var cntF = IntArray(n)
    var cntL = IntArray(n)
    var cnt = IntArray(n * n)
    for (i in 0..m - 1) {
        var (f, l) = readInts()
        f -= 1
        l -= 1
        cntF[f] += 1
        cntL[l] += 1
        cnt[f * n + l] += 1
        if (i == 0) {
            myF = f
            myL = l
        }
    }
    var ans = 0
    for (i in 0..n - 1) {
        for (j in 0..n - 1) {
            if (i == j)
                continue
            var place = 0
            if (myF == i && myL == j) {

            } else {
                if (myF == i || myL == j) {
                    place = cnt[i * n + j]
                } else {
                    place = cntF[i] + cntL[j] - cnt[i * n + j]
                }
            }
            ans = max(ans, place)
        }
    }
    println(ans + 1)
}