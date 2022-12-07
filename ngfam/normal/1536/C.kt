import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun gcd(x: Int, y: Int): Int = if (y == 0) x else gcd(y, x % y);

fun main() {
    val nTest = readInt();
    repeat(nTest) {
        val n = readInt();
        val s = readLine()!!;

        val mymap = mutableMapOf<Pair<Int, Int>, Int>();
        val ans = mutableListOf<Int>()
        var countD = 0;
        var countK = 0;

        for(c in s) {
            if (c == 'D') {
                countD += 1;
            }
            else {
                countK += 1;
            }

            if (min(countD, countK) == 0) {
                ans.add(countD + countK);
            }
            else {
                var g = gcd(countD, countK);
                var wd = countD / g;
                var wk = countK / g;
//                println("$wd $wk");
                var item = Pair(wd, wk);
                mymap[item] = (mymap[item]?:0) + 1;
                ans.add(mymap[item]?:0);
            }
        }
        println(ans.joinToString(" "));
    }
}