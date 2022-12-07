
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs


fun main(args: Array<String>) {
    var nTest = readInt();

    while(nTest > 0) {
        nTest -= 1;
        val n = readInt();
        var a = readInts();

        var flag = false;
        for (x in a) {
            if (x < 0) {
                flag = true;
            }
        }

        if (flag) {
            println("NO");
        }
        else {
            println("YES");
            println(101);
            for (x in 0..100) {
                print("$x ")
            }
            println("")
        }
    }
}