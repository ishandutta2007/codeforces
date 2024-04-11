import kotlin.math.min;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    var t = readInt();
    for (i in 0 until t) {
        var s = readLn();
        val n = s.length;
        
        var ans = 0;
        var run = 0;
        for (i in 0 until n) {
            if (s[i] == 'w') {
                ans++;
                ans += run/2;
                run = 0;
            } else {
                run++;
            }
        }
        ans += run/2;
        println(ans);
    }
}