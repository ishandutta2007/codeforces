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
 
fun main(args: Array<String>) {
    var t = readInt()
    for (tt in 0 until t) {
        var (n, k) = readInts()
        var s = readLn()
        var cnt = 0
        for (i in 0 until n)
            if (s[i] == '1')
                cnt += 1
        val a: ArrayList<Int> = ArrayList()
        for (i in 0 until n)
            a.add(i)
        var ans = 0
        var cur = 0
        while (cnt > 0) {
            if (s[a[cur]] == '1')
                cnt -= 1
            a.removeAt(cur)  
            if (a.size > 0)
                cur = (cur + k - 1) % a.size
            ans += 1
        }
        println(ans)
    }
}