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
    for (i in 0 until t) {
        var (x, y) = readLongs()
        var ans = 0L
        var cur = x
        while (cur <= y)
            cur *= 10
        while (cur >= x) {
            while (y >= cur) {
                y -= cur 
                ans++
            }
            cur /= 10;
        }
        ans += y;
        println(ans)
    }
}