import java.util.*
import kotlin.collections.ArrayDeque

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun binpow(b : Long, p : Long, mod : Long) : Long {
    var pw = p
    var cur = b
    var ans = 1L
    while (pw > 0) {
        if ((pw and 1) > 0)
            ans = (ans * cur) % mod

        cur = (cur * cur) % mod
        pw = pw shr 1
    }
    return ans
}

fun main() {
    var t = readInt()
    while (t-- > 0) {
        var n = readInt()
        var a = readInts()

        var b = ArrayDeque<Pair<Int, Int>>()
        for (i in a.indices) {
            b.addLast(Pair(a[i], i))
        }

        b.sortBy{ it.first }

        var used = 0
        var ans = MutableList<Int>(0) { 0 }
        while (!b.isEmpty()) {
            var now = b.first().first
            var tmp = b.first().second
            b.removeFirst()

            var req = now - used
            while (!b.isEmpty() && req > 0) {
                ans.add(b.last().second + 1)
                b.removeLast()
                req--
            }

            ans.add(tmp + 1)
            used = 1
        }

        println(ans.joinToString(" "))
    }
}