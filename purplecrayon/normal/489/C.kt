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

fun good(m: Int, s: Int): Boolean {
    var mn = 0;
    var mx = 9*m;
    return mn <= s && s <= mx;
}
fun solve() {
    var (m, s) = readInts();
    if (s == 0 && m == 1){ println("0 0"); return; }
    else if (s == 0){ println("-1 -1"); return; }

    if (!good(m, s)){ println("-1 -1"); return; }

    var mn_len_left = m;
    var mn_sum_left = s;

    var mx_len_left = m;
    var mx_sum_left = s;

    var mn = "";
    var mx = "";
    for (i in 0 until m) {
        var cmn = 10;
        var cmx = -1;

        var lo = 0;
        if (i == 0) lo = 1;

        for (j in lo until 10) {
            var mn_new_len = mn_len_left-1;
            var mn_new_sum = mn_sum_left-j;
            if (good(mn_new_len, mn_new_sum)) {
                cmn = min(cmn, j);
            }

            var mx_new_len = mx_len_left-1;
            var mx_new_sum = mx_sum_left-j;
            if (good(mx_new_len, mx_new_sum)) {
                cmx = max(cmx, j);
            }
        }
        mn += cmn.toString();
        mx += cmx.toString();
        mn_len_left--;
        mn_sum_left -= cmn;

        mx_len_left--;
        mx_sum_left -= cmx;
    }
    println("$mn $mx");
}
fun main() {
    val T = 1;
    for (test in 0 until T) {
        solve();
    }
}