private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    val t = readInt()
    for (i in 1..t) {
        var s = readLn().toCharArray().sorted().joinToString("")
        println(if (s[0] == s[s.length - 1]) -1 else s)
    }
}