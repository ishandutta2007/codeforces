import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt();
    var a = readInts();

    a = a.sorted();
    var ans = 0;
    for(i in 0..n-1 step 2) {
        ans = ans + a[i + 1] - a[i];
    }

    println(ans);
}