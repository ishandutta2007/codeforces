import java.util.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var (n, k) = readLongs()
        var s = readLn()

        var sb = StringBuilder(s)
        var cnt1 = 0L
        for (i in 0 until n.toInt()) {
            if (sb[i] == '0') {
                var take = Math.min(k, cnt1).toInt()
                sb[i] = sb[i - take].also { sb[i - take] = sb[i] }
                k -= take
            } else {
                cnt1++
            }
        }

        println(sb)
    }
}