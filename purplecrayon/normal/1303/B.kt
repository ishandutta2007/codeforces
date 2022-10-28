import kotlin.math.min;
import kotlin.math.max;
import kotlin.math.abs;
import java.util.*;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun solve() {
    var (n, g, b) = readLongs();
    var ans = (b+g)*(((n+1)/2)/g);
    if (((n+1)/2)%g != 0L) ans += ((n+1)/2)%g;
    else ans -= b;
    ans = max(ans, n);
    println(ans);
}
fun main() {
    var T = readInt();
    for (test in 0 until T) {
        solve();
    }
}