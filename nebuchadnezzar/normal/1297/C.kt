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
        var arr = readInts()
        var best = 0
        var smallest_pos = 1e9.toInt()
        var smallest_neg = -1e9.toInt()
        for (num in arr) {
            if (num > 0) {
                best += num
                smallest_pos = min(smallest_pos, num)
            } else if (num < 0) {
                smallest_neg = max(smallest_neg, num)
            }
        }
        if (smallest_pos < -smallest_neg) {
            println(best - smallest_pos)
            var found = false
            for (num in arr) {
                if (num == smallest_pos && !found) {
                    found = true
                    print(0)
                } else {
                    if (num > 0) {
                        print(1)
                    } else {
                        print(0)
                    }
                }
            }
        } else {
            println(best + smallest_neg)
            var found = false
            for (num in arr) {
                if (num == smallest_neg && !found) {
                    found = true
                    print(1)
                } else {
                    if (num > 0) {
                        print(1)
                    } else {
                        print(0)
                    }
                }
            }
        }
        println()
    }
}