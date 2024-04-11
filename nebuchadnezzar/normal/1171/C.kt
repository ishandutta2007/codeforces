private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        var s = readLn()
        var arrs = s.toCharArray().sortedArray()
        var flag = true;
        for (j in 0 until s.length) {

            if (arrs[j] != arrs[s.length - 1 - j]) {
                flag = false;
                break;
            }
        }
        if (flag) {
            println(-1)
        } else {
            println(arrs.joinToString(separator = ""))
        }
    }
}