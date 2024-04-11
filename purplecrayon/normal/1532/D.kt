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
    var n = readInt();
    var a = readInts();
    var cnt = IntArray(101);
    for (i in 0 until n) {
        cnt[a[i]]++;
    }
    var x = mutableListOf<Int>()
    for (i in 0 until 101) {
        cnt[i] = cnt[i]%2;
        if (cnt[i] > 0) {
            x.add(i);
        }
    }
    assert(x.size%2 == 0);
    var ans = 0;
    for (i in 0 until x.size step 2) {
        ans += x[i+1]-x[i];
    }
    println(ans);
}