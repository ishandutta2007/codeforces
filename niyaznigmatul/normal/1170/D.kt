import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val m = readInt()
    val b = readInts().toIntArray()
    val n = b.count { it == -1 }
    val a = Array(n) { mutableListOf<Int>()}
    val q = IntArray(n) { it }
    var nq = n
    var cur = 0
    val toAdd = IntArray(n)
    while (cur < m) {
        var have = 0
        for (et in 0 until nq) {
            val z = q[et]
            val v = b[cur++]
            if (v == -1) {
            } else {
                a[z].add(v)
                toAdd[have++] = z
            }
        }
        System.arraycopy(toAdd, 0, q, 0, have)
        nq = have
    }
    println(n)
    for (x in a) {
        println("${x.size} ${x.joinToString(" ")}")
    }
}