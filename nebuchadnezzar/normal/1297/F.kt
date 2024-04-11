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
        var (n, m) = readInts()
        var segs = ArrayList<Pair<Pair<Int, Int>, Int>>()
        for (j in 0 until n) {
            var (a, b) = readInts()
            segs.add(Pair(Pair(a, b), j))
        }

        var sorted_segs = segs.sortedBy { it.first.first }

        var shift = 0
        var prev = -1
        var have = TreeMap<Int, ArrayList<Int>>()
        var ok = true
        var ans = Array<Int>(n, {0})
        for (seg in sorted_segs) {
            System.err.println(seg.first.first.toString() + " " + seg.first.second.toString() + " " + seg.second.toString())
            while (prev < seg.first.first) {
                if (have.isEmpty()) {
                    break
                }
                for (qqq in 0 until m) {
                    if (have.isEmpty()) {
                        break
                    }
                    var lowest = have.firstEntry()
                    shift = max(shift, prev - lowest.key)
                    var who = lowest.value.last()
                    lowest.value.removeAt(lowest.value.size - 1)
                    ans[who] = prev
                    if (lowest.value.isEmpty()) {
                        have.remove(lowest.key)
                    }
                }
                prev += 1
            }

            if (!ok) {
                break
            }
            if (!have.contains(seg.first.second)) {
                have.put(seg.first.second, ArrayList())
            }
            have.get(seg.first.second)?.add(seg.second)

            prev = seg.first.first
        }

        while (!have.isEmpty()) {
            for (qqq in 0 until m) {
                if (have.isEmpty()) {
                    break
                }
                var lowest = have.firstEntry()
                shift = max(shift, prev - lowest.key)
                var who = lowest.value.last()
                lowest.value.removeAt(lowest.value.size - 1)
                ans[who] = prev
                if (lowest.value.isEmpty()) {
                    have.remove(lowest.key)
                }
            }
            prev += 1
        }

        println(shift)
        for (num in ans) {
            print(num.toString() + " ")
        }
        println()
    }
}