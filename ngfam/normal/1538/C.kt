private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    val nTest = readInt();
    repeat(nTest) {
        val (n, l, r) = readInts();
        val a = readInts().sorted();

        fun countLessOrEqualTo(x: Int): Int {
            var l = 0;
            var r = n - 1;
            var ans = -1;

            while (l <= r) {
                val mid = (l + r) / 2;
                if (a[mid] <= x) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return ans + 1;
        };

        var ans: Long = 0;

        for(x in a) {
            val wl = l - x;
            val wr = r - x;
            ans = ans + countLessOrEqualTo(wr) - countLessOrEqualTo(wl - 1);
            if (wl <= x && x <= wr) {
                ans -= 1;
            }
        }

        println(ans / 2);
    }
}