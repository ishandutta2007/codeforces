fun main() {
    val lines = (1..readInt()).map { readLn() }.sortedBy { it.length }
    for (i in 1 until lines.size) {
        if (!lines[i].contains(lines[i-1])) {
            println("NO")
            return
        }
    }
    println("YES")
    println(lines.joinToString("\n"))
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }