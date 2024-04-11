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
    var (n, m) = readInts()
    val set = HashSet<String>() 
    for (i in 0 until n) {
        set.add(readLn())
    }
    var q = readInt()
    for (qq in 0 until q) {
        var t = readLn()
        var ans = 0
        for (i in 0 until m + 1) {
            if ((i == 0 || t[i] != t[i - 1]) && set.contains(t.substring(0, i) + t.substring(i + 1, m + 1)))
                ans += 1
        }
        println(ans)
    }
}