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
    var a = readInts()
    var q = readInt()
    val requests: Array<ArrayList<Par>> = Array<ArrayList<Par>>(n + 1) { ArrayList<Par>() }
    val ans = LongArray(q) {0}
    for (i in 0 until q) {
        var (l, r) = readInts()
        l--
        r--
        requests[r].add(Par(l, i))
    }
    val st: ArrayList<Int> = ArrayList()
    val pos: ArrayList<Int> = ArrayList()
    val sums: ArrayList<Long> = ArrayList()
    for (i in 0 until n) {
        while (st.size > 0 && st.last() <= a[i]) {
            st.removeLast()
            pos.removeLast()
            sums.removeLast()
        }
        if (sums.size > 0)
            sums.add(sums.last() + a[i] * 1L * (i - pos.last()))
        else
            sums.add(a[i] * 1L * (i + 1))
        st.add(a[i])
        pos.add(i)
            
        for (req in requests[i]) {
            var bl = -1
            var br = st.size - 1
            while (br - bl > 1) {
                var bm = (bl + br) / 2
                if (pos.get(bm) >= req.l)
                    br = bm;
                else
                    bl = bm;
            }
            ans[req.r] = (pos.get(br) - req.l + 1) * 1L * st.get(br) + sums.last() - sums.get(br); 
        }
    }
    for (i in 0 until q) {
        print(ans[i])
        print(" ")
    }
    println();
}