private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    val ntest = readInt();
    repeat(ntest) {
        val (l, r) = readInts();

        var ans: Long = (r - l).toLong();
        var p: Long = 1;
        repeat(9) {
            p *= 10;
            val to = p - l % p;
            if (l + to <= r) {
                ans += 1;
                ans += (r - (l + to)) / p;
            }
        }
        println(ans);
    }
}