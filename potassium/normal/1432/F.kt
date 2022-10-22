import java.util.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var (n, m, d) = readInts()
    var c = readInts()

    var rem = c.sum()
    var totalLen = rem + (d - 1) * (m + 1)

    if (n > totalLen) {
        println("NO")
        return
    }

    println("YES")

    var ans = MutableList<Int>(n) { 0 }
    var ptr = 0
    for (i in 0 until m) {
        var take = Math.min(n - ptr - rem, d - 1)
        ptr += take
        for (j in ptr until ptr + c[i]) {
            ans[j] = i + 1
        }
        ptr += c[i]
        rem -= c[i]
    }

    println(ans.joinToString(" "))
}