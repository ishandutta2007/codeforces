import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var (n, m) = readInts();

    var stringMap = TreeMap<String, Int>();

    repeat(n) {
        var cur = readLn();
        if (!stringMap.containsKey(cur)) {
            stringMap.put(cur, 1);
        }
        else {
            stringMap.put(cur, stringMap.get(cur)!! + 1)
        };
    }

    var q = readInt();
    repeat(q) {
        var cur = readLn();
        var ans = 0;
        var done = mutableSetOf<String>();

        for(i in 0..m){
            var now = String();
            if (i > 0) now += cur.substring(0, i);
            if (i < m) now += cur.substring(i + 1, m + 1);

            if (!done.contains(now)) {
                done.add(now);
                if (stringMap.containsKey(now)) {
                    ans = ans + stringMap.get(now)!!;
                }
            }
        }
        println(ans);
    }
}