import kotlin.math.max;
import kotlin.math.min;
import kotlin.math.abs;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main() {
    val INF = 1000000000;
    
    var t = readInt();
    for (i in 0 until t) {
        var n = readInt();
        var a = readInts();
        var b = readInts();
        
        var ans = -1;
        var pr = -1;
        for (i in 0 until n) {
            var cur = INF;
            var idx = i
            for (j in 0 until n) {
                cur = min(cur, abs(a[j]-b[idx]));
                idx = (idx+1)%n;
            }
            ans = max(ans, cur);
            if (ans == cur) pr = i;
        }
        var x = mutableListOf<Int>()
        for (i in pr until n) x.add(i+1);
        for (i in 0 until pr) x.add(i+1);
        println(x.joinToString(" "));
    }
}