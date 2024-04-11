private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    val nTest = readInt();
    repeat(nTest) {
        val n = readInt();
        val a = readInts();

        var sum: Long = 0;
        for (x in a) {
            sum += x;
        }

        if (sum % n != 0.toLong()) {
            println(-1);
        }
        else {
            var ans = 0;
            for(x in a) {
                if (x.toLong() > sum / n) {
                    ans += 1;
                }
            }
            println(ans);
        }
    }
}