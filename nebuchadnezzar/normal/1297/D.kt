import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        var (n, k) = readInts()
        var arr_vals = readLongs()
        var arr = ArrayList<Pair<Long, Int>>()
        for (j in 0 until n) {
            arr.add(Pair(arr_vals[j], j))
        }
        var sorted_arr = arr.sortedBy { it.first }
        var l = sorted_arr[n - 1].first - 1
        var r = 1e9.toLong() + k + 100
//        System.err.println(l.toString() + " " + r.toString())
        while (r - l > 1) {
            var mid = (l + r) / 2
            var prev = 2e9.toLong() + 1234
            var left = k.toLong()
            for (j in n - 1 downTo 0) {
                var q = min(min(sorted_arr[j].first + left, prev - 1), mid)
                left -= q - sorted_arr[j].first
                prev = q
            }

            if (left > 0) {
                l = mid
            } else {
                r = mid
            }
        }
//        System.err.println(r)
        var ans = Array<Long>(n, {0})
        var prev = 2e9.toLong() + 1234
        var left = k.toLong()
        for (j in n - 1 downTo 0) {
            var q = min(min(sorted_arr[j].first + left, prev - 1), r)
//            System.err.println(sorted_arr[j].second.toString() + " " + (q - sorted_arr[j].first).toString())
            ans[sorted_arr[j].second] = q - sorted_arr[j].first
            left -= q - sorted_arr[j].first
            prev = q
        }

        for (num in ans) {
            print(num.toString() + " ")
        }
        println()
    }
}