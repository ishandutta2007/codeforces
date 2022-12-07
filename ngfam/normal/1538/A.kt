import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    val ntest = readInt();
    repeat(ntest) {
        val n = readInt();
        val a = readInts();

        var ans = n;
        var x = -1;
        var y = -1;
        for(i in 0..n-1) {
            if (a[i] == 1) x = i;
            if (a[i] == n) y = i;
        }

        ans = min(ans, x + 1 + n - y);
        ans = min(ans, y + 1 + n - x);
        ans = min(ans, max(x, y) + 1);
        ans = min(ans, n - min(x, y));
        println(ans);
    }
}