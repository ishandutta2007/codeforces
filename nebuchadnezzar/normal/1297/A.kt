import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var t = readInt()
    for (i in 0 until t) {
        var n = readInt()
        if (n <= 999) {
            println(n)
        } else if (n < 999500) {
            if (n % 1000 < 500) {
                println((n / 1000).toString() + "K")
            } else {
                println((n / 1000 + 1).toString() + "K")
            }
        } else {
            if (n % 1000000 < 500000) {
                println((n / 1000000).toString() + "M")
            } else {
                println((n / 1000000 + 1).toString() + "M")
            }
        }
    }
}