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
        var n = readInt()
        var x = readInts()
        var was = 0
        for (i in 0 until n - 1) {
            if ((x[i + 1] - x[i]) % 2 == 0)
                was = 1
        }
        if (was == 1)
            println("YES")
        else
            println("NO")
    }
}