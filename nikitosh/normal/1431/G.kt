import java.util.Collections
import kotlin.math.min
import kotlin.math.max
import kotlin.math.abs

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles


fun main(args: Array<String>) {
    var (n, k) = readInts()
    var a = readInts().sorted()
    var sums = IntArray(n + 1) {0}
    for (i in 0 until n) {
        sums[i + 1] = sums[i] + a[i]
    }
    var ans = 0
    for (i in 0 until (k + 1)) 
        for (j in 0 until (k + 1 - i)) {
            var cur = sums[2 * i] - 2 * sums[i] + sums[n] - 2 * sums[n - j] + sums[n - 2 * j]
            var r = k - i - j
            //println("${i} ${j} ${cur}")
            for (g in 2 * i until n) {
                if (g + 2 * r > n - 2 * j)
                    break
                ans = max(ans, cur + sums[g + 2 * r] - 2 * sums[g + r] + sums[g])
            }
        }
    println(ans)
}