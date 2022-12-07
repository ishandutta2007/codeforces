private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    val nTest = readInt();
    repeat(nTest) {
        var (n, k) = readInts();

        var ans = String();
        for(i in 'a'..'a'+k-1) {
            repeat(n / k) {
                ans = ans + i;
            }
        }

        repeat(n % k) {
            ans = ans + 'a';
        }
        println(ans);
    }
}