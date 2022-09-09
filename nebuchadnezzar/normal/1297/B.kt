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
        var n = readInt()
        var segs = ArrayList<Pair<Int, Int>>();
        for (j in 0 until n) {
            var (a, b) = readInts()
            segs.add(Pair(a, b))
        }
        var found = false
        for (seg in segs) {
            var p = seg.first
            var cnt = 0
            for (seg2 in segs) {
                if (seg2.first <= p && p <= seg2.second) {
                    cnt += 1
                }
            }
            if (cnt == 1) {
                println(p)
                found = true
                break
            }
            p = seg.second + 1
            cnt = 0
            for (seg2 in segs) {
                if (seg2.first <= p && p <= seg2.second) {
                    cnt += 1
                }
            }
            if (cnt == 1) {
                println(p)
                found = true
                break
            }
        }
        if (!found) {
            println(-1)
        }
    }
}