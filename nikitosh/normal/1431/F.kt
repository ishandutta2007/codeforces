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

class Par(val value: Int, val ind: Int) : Comparable<Par> {
    override operator fun compareTo(other: Par): Int {
        if (this.value > other.value) return 1
        if (this.value < other.value) return -1
        if (this.ind > other.ind) return 1
        if (this.ind < other.ind) return -1
        return 0
    }
}

fun main(args: Array<String>) {
    var (n, k, x) = readInts()
    var a = readInts()
    var l = -1.toLong()
    var r = (1e12).toLong()
    var s = sortedSetOf<Par>();
    while (r - l > 1) {
        var m = (l + r) / 2
        //println("${m}")
        var siz = 0
        var sum = 0.toLong()
        var removed = 0
        var ok = true
        s.clear()
        for (i in 0 until n) {
            siz += 1
            sum += a[i]
            //println("sum=${sum}")
            s.add(Par(a[i], i))
            if (sum > m) {
                if (removed >= k) {
                    ok = false
                    break
                }
                removed += 1
                siz -= 1
                var lst = s.last()
                sum -= lst.value
                s.remove(lst)
            }
            if (siz == x) {
                s.clear()
                siz = 0
                sum = 0
            }
        }
        if (ok)
            r = m
        else
            l = m
    }
    println(r)
}