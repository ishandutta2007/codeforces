
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main(args: Array<String>) {
    val n = readInt();
    var a = readInts();

    var ans = 0;
    var max = -1;
    var secondMax = -1;

    for(num in a) {
        if (max > num && secondMax > num) {
            ans += 1;
        }
        if (num > max) {
            secondMax = max;
            max = num;
        } else if (num > secondMax) {
            secondMax = num;
        }
    }
    println(ans);
}