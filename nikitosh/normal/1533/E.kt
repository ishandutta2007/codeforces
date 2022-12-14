import kotlin.math.min
import kotlin.math.max
import java.io.*
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    val bi = BufferedReader(InputStreamReader(System.`in`));
    val n = Integer.parseInt(bi.readLine())
    
    var line = bi.readLine()
    var a = IntArray(n, {it -> 0})
    var it = 0
    for (numStr in line.split(" ")) {
        a[it] = Integer.parseInt(numStr)
        it += 1
    }
    a.sort()
    
    line = bi.readLine()
    var b = IntArray(n + 1, {it -> 0})
    it = 0
    for (numStr in line.split(" ")) {
        b[it] = Integer.parseInt(numStr)
        it += 1
    }
    b.sort()

    val m = Integer.parseInt(bi.readLine())
    
    line = bi.readLine()
    var c = IntArray(m, {it -> 0})
    it = 0
    for (numStr in line.split(" ")) {
        c[it] = Integer.parseInt(numStr)
        it += 1
    }
    
    //var a = readInts().sorted()
    //var b = readInts().sorted()
    //var m = readInt()
    //var c = readInts()
    
    val pr = ArrayList<Int>()
    pr.add(b[0] - a[0])
    for (i in 1 until n) 
        pr.add(max(pr.last(), b[i] - a[i]))
    val suf = ArrayList<Int>()
    suf.add(b[n] - a[n - 1])
    for (i in n - 1 downTo 1)
       suf.add(max(suf.last(), b[i] - a[i - 1]))
    suf.reverse()
    
    for (i in 0 until m) {
        var k = c[i]
        var l = -1
        var r = n
        while (r - l > 1) {
            var m = (l + r) / 2
            if (a[m] < k)
                l = m
            else
                r = m
        }
        var ind = r
        var ans = b[ind] - k
        if (ind != 0)
            ans = max(ans, pr[ind - 1])
        if (ind != n)
            ans = max(ans, suf[ind])
        print(ans)
        print(" ")
    }
}