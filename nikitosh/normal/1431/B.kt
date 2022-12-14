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
        var s = readLn()
        var n  = s.length
        var last = false
        var ans = 0
        for (c in s) {
            if (c == 'v' && last) {
                last = false;
                ans++;
            } else if (c == 'v')
                last = true;
            else
                last = false;
            if (c == 'w')
                ans++;
        }
        println(ans)
    }
}