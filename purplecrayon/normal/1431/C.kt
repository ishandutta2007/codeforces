import kotlin.math.max;

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
        var (n, k) = readInts();
        var a = readInts();
        
        var ans = 0;
        for (i in 0 until n) {
            var cnt = (n-i)/k;
            var sm = 0;
            for (j in i until i+cnt) {
                sm += a[j];
            }
            ans = max(ans, sm);
        }
        println(ans);
    }
}