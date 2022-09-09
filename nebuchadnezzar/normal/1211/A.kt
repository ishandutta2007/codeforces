private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt()
    var arr = readInts()
    var a = 0
    var b = 0
    var c = 0
    while (b != arr.size && arr[b] == arr[a]) {
        ++b
    }
    if (b == arr.size) {
        println("-1 -1 -1")
        return
    }
    c = b
    while (c != arr.size && (arr[c] == arr[a] || arr[c] == arr[b])) {
        ++c
    }
    if (c == arr.size) {
        println("-1 -1 -1")
        return
    }
    if (arr[a] > arr[b]) {
        var tmp = a
        a = b
        b = tmp
    }
    if (arr[b] > arr[c]) {
        var tmp = b
        b = c
        c = tmp
    }
    if (arr[a] > arr[b]) {
        var tmp = a
        a = b
        b = tmp
    }
    println((a + 1).toString() + " " + (b + 1).toString() + " " + (c + 1).toString())
}