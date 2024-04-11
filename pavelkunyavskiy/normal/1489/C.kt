import java.util.regex.Pattern

fun main() {
    readInt()
    println(readLn().split(Pattern.compile("[^x]")).map { Math.max(0, it.length - 2) }.sum())
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }