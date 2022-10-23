private fun solve() {
    readInt()
    val a = readInts().toIntArray()
    var i = 0
    var j = a.size - 1
    var ans = 0
    while (i < j) {
        while (i < j && a[i] == 0) i++
        while (i < j && a[j] == 1) j--
        if (i < j) {
            ans++
            i++
            j--
        }
    }
    println(ans)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }