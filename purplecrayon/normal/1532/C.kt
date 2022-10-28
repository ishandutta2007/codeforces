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
    for (tt in 0 until t) {
        var (n, k) = readInts();
        var a = IntArray(k);
        
        var p = 0;
        for (i in 0 until n) {
            a[p]++;
            p = (p+1)%k;
        }
        for (i in 0 until k) {
            for (j in 0 until a[i]) print('a'+i);
        }
        println("");
    }
}