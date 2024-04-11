import java.util.Comparator
import java.util.concurrent.ConcurrentMap

fun main() {
    val n = readInt()
    val divs = IntArray(n + 1)
    for (i in 1..n) {
        for (j in i..n step i) {
            divs[j] += 1
        }
    }
    var psum = 0
    val order = (1..n).sortedWith(compareBy({divs[it] -(n / it)})).reversed()
    println(order.map { psum += divs[it] - (n / it); psum }.joinToString(" "))
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }