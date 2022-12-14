import kotlin.math.min
import kotlin.math.max
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
class Par(val l: Int, val r: Int) : Comparable<Par> {
    override operator fun compareTo(other: Par): Int {
        if (this.l < other.l) return 1
        if (this.l > other.l) return -1
        if (this.r < other.r) return 1
        if (this.r > other.r) return -1
        return 0
    }
} 
 
fun main(args: Array<String>) {
    var n = readInt()
    var cnt = IntArray(n + 1) {0}
    for (i in 1 until n + 1) {
        for (j in 2 * i until n + 1 step i)
            cnt[j]++
    }
    var pairs: ArrayList<Par> = ArrayList()
    var s = sortedSetOf<Par>()
    for (i in 1 until n + 1) {
        s.add(Par(cnt[i], i))
    }
    var ans = 0
    for (i in 0 until n) {
        var elemFirst = s.pollFirst()
        ans += elemFirst.l
        var k = elemFirst.r
        for (j in 1 until k + 1) {
            if (j * j > k)
                break;
            if (j * j == k) {
                if (s.remove(Par(cnt[j], j))) {
                    cnt[j]--
                    s.add(Par(cnt[j], j))
                }
            } else if (k % j == 0) {
                if (s.remove(Par(cnt[j], j))) {
                    cnt[j]--
                    s.add(Par(cnt[j], j))
                }
                
                var l = k / j
                if (s.remove(Par(cnt[l], l))) {
                    cnt[l]--
                    s.add(Par(cnt[l], l))
                }
            }
        }
        print(ans)
        print(" ")
    }
    println();
}