private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map {it.toInt()}

fun main() {
    val n = readInt()
    val s = readLn()
    if (s.length == s.toSet().size && s.length > 1)
        print("NO")
    else
        print("YES")
}