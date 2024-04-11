private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var q = readInt()
    for (i in 0 until q) {
        var (x, y) = readInts()
        if (x > y) {
            var tmp = x
            x = y
            y = tmp
        }
        var a = x - 1
        var b = 1
        var c = y - a
        println(a.toString() + " " + b.toString() + " " + c.toString())
    }
}