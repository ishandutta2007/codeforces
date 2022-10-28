import kotlin.math.min;

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun bld(c: String, a: MutableList<String>, n: Int): Pair<Boolean, MutableList<Char>> {
    var m = a.size;
    var ans = MutableList<Char>(m){ index -> '?' };
    for (i in 1 until n) {
        var id = mutableListOf<Int>();
        for (j in 0 until m) {
            if (a[j].length == i) {
                id.add(j);
            }
        }
        if (c.startsWith(a[id[0]]) && c.endsWith(a[id[1]])) {
            ans[id[0]] = 'P';
            ans[id[1]] = 'S';
        } else if (c.endsWith(a[id[0]]) && c.startsWith(a[id[1]])) {
            ans[id[0]] = 'S';
            ans[id[1]] = 'P';
        } else return Pair(false, ans);
    }
    return Pair(true, ans);
}
fun main() {
    var n = readInt();
    var s = mutableListOf<String>();
    var big = mutableListOf<String>();
    
    for (i in 0 until 2*n-2) {
        var c = readLn();
        s.add(c);
        if (c.length == n-1) {
            big.add(c);
        }
    }
    assert(big.size == 2);
    var s1 = big[0]+big[1][n-2];
    var s2 = big[1][0]+big[0];
    var (good1, ans1) = bld(s1, s, n);
    var (good2, ans2) = bld(s2, s, n);
    if (good1) {
        println(ans1.joinToString(""));
    } else if (good2) {
        println(ans2.joinToString(""));
    } else assert(false);
}