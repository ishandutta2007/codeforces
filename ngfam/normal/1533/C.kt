private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var ntest = readInt();
    repeat(ntest) {
        var (n, k) = readInts();
        var s = readLn();

        var totalLiked = 0;
        for(x in s) {
            if (x == '1') {
                totalLiked += 1;
            }
        }

        var eaten = mutableListOf<Boolean>();
        repeat(n) {
            eaten.add(false);
        }

        var toEat = 0;
        var ans = 0;
        while(totalLiked > 0) {
            ans += 1;
            eaten[toEat] = true;

            if (s[toEat] == '1') {
                totalLiked -= 1;
            }
            if (totalLiked == 0) break;
            repeat(k) {
                toEat = (toEat + 1) % n;
                while(eaten[toEat]) toEat = (toEat + 1) % n;
            }
        }
        println(ans);
    }
}