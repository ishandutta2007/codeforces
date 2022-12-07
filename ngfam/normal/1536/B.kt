import java.util.*
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main(args: Array<String>) {
    var nTest = readInt();

    while(nTest > 0) {
        nTest -= 1;
        var n = readInt();
        var s = readLn();

        var set = TreeSet<String>();
        for (i in 0..n-1) {
            for(j in 1..3) {
                if (i + j <= n) {
                    set.add(s.substring(i, i + j));
                }
            }
        }

        var flag = false;
        var res = String();
        for(i in 'a'..'z') {
            var cur = String();
            cur = cur + i;
            if (!flag && !set.contains(cur)) {
                res = cur;
                flag = true;
            }
        }

        if (!flag)
            for(i in 'a'..'z') {
                for(j in 'a'..'z') {
                    var cur = String();
                    cur = cur + i;
                    cur = cur + j;
                    if (!flag && !set.contains(cur)) {
                        res = cur;
                        flag = true;
                    }
                }
            }


        if (!flag)
            for(i in 'a'..'z') {
                for(j in 'a'..'z') {
                    for (z in 'a'..'z') {
                        var cur = String();
                        cur = cur + i;
                        cur = cur + j;
                        cur = cur + z;
                        if (!flag && !set.contains(cur)) {
                            res = cur;
                            flag = true;
                        }
                    }
                }
            }
        println(res);
    }
}