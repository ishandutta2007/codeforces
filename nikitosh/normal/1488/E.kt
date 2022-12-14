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
        if (this.l > other.l) return 1
        if (this.l < other.l) return -1
        if (this.r < other.r) return 1
        if (this.r > other.r) return -1
        return 0
    }
} 
 
fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var n = readInt()
        var a = readInts()
        var end = IntArray(n + 1) {0}
        
        for (i in 0 until n) {
            end[a[i]] = i
        } 
        
        var seq: ArrayList<Int> = ArrayList()
        for (i in 0 until n) {
            if (end[a[i]] != i)
                seq.add(end[a[i]])
        }
        var r = seq.size
        var d = IntArray(r + 1) {0}
        var was = IntArray(r + 1) {0}
        d[0] = 2 * n
        for (k in seq) {
            var bl = 0
            var br = r
            while (br - bl > 1) {
                var bm = (bl + br) / 2
                if (d[bm] < k)
                    br = bm
                else
                    bl = bm
            }
            if (k > d[br] && k < d[br - 1])
                d[br] = k
                if (a[k] != a[k - 1])
                    was[br] = 1
        }
        var ans = 1
        for (i in 0 until r + 1)
            if (d[i] != 0) {
                ans = 2 * i + was[i]
            }
        ans = max(ans, 1)
            
        println(ans)
    }
}