import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var n = readInt();
    var a = readInts();

    var answer = mutableListOf<Int>();

    var sum = 0.toLong();
    for(i in 0..n-1) {
        sum += a[i];
    }

    var max1 = Int.MIN_VALUE;
    var max2 = Int.MIN_VALUE;

    for(i in 0..n-1){
        if(a[i] > max1) {
            max2 = max1;
            max1 = a[i];
        } else if (a[i] > max2) {
            max2 = a[i];
        }
    }

    for(i in 0..n-1) {
        var cur = max1;
        if (a[i] == cur) cur = max2;

        if (cur.toLong() * 2 == sum - a[i]) {
            answer.add(i + 1);
        }
    }

    println(answer.size);
    println(answer.joinToString(" "));
}