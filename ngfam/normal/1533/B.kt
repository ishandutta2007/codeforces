private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main() {
    var ntest = readInt();
    repeat(ntest){
        var n = readInt();
        var a = readInts();

        var flag = false;
        a = a.sorted();
        for(i in 0..n-2){
            if (a[i + 1] % 2 == a[i] % 2) {
                flag = true;
            }
        }

        if(flag) println("YES");
        else println("NO");
    }
}