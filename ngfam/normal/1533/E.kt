import kotlin.math.max

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var n = readInt();
    var a = readInts().sorted();
    var b = readInts().sorted();
    var m = readInt();
    var c = readInts();

    var curMax = Int.MIN_VALUE;
    var pref = mutableListOf<Int>();
    var suff = mutableListOf<Int>();

    for(i in 0..n-1) {
        curMax = max(curMax, b[i] - a[i]);
        pref.add(curMax);
    }

    curMax = Int.MIN_VALUE;
    for(i in n-1 downTo 0) {
        curMax = max(curMax, b[i + 1] - a[i]);
        suff.add(curMax);
    }

    suff.reverse();

    var answer = mutableListOf<Int>();
    for(v in c) {
        var low = 0;
        var high = n - 1;
        var ans = -1;

        while(low <= high) {
            var mid = (low + high) / 2;
            if (a[mid] <= v) {
                ans = mid;
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        var result = b[ans + 1] - v;
        if (ans >= 0) result = max(result, pref[ans]);
        if (ans < n - 1) result = max(result, suff[ans + 1]);
        answer.add(result);
    }

    println(answer.joinToString(" "));
}