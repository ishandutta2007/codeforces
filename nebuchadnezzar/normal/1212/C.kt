private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n, k) = readInts()
    var arr = readInts().sorted().toIntArray()
    if (k == 0) {
        if (arr[0] == 1) {
            println(-1)
        } else {
            println(1)
        }
    } else {
        if (k < n && arr[k] == arr[k - 1]) {
            println(-1)
        } else {
            println(arr[k - 1])
        }
    }
}