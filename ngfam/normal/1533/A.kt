import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var ntest = readInt();
    repeat(ntest) {
        var (n, k) = readInts();
        var ans = 0;
        repeat(n) {
            var (l, r) = readInts();
            if(l <= k) ans = max(ans, r - k + 1);
        }
        println(ans);
    }
}