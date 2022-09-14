private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    var a = ArrayList(readInts())
    var b = ArrayList(readInts())
    for (i in 0..2) {
        b[i] -= a[i]
        if (b[i] < 0) {
            println("NO")
            return
        }
        if (i < 2)
            b[i + 1] += b[i]
    }
    println("YES")
}