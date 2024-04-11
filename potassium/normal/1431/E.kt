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

class comp : Comparator<Pair<Int, Int>> {
    override fun compare(o1: Pair<Int, Int>?, o2: Pair<Int, Int>?): Int {
        if (o1!!.first != o2!!.first) {
            return o1.first.compareTo(o2.first)
        } else {
            return o1.second.compareTo(o2.second)
        }
    }
}

fun main() {
    var t = readInt()
    while (t-- > 0) {
        solve()
    }
}

fun solve() {
    var n = readInt()
    var a = readInts()
    var b = readInts()

    var maxv = 0
    var best = 0
    for (i in 0 until n) {
        var dist = Integer.MAX_VALUE
        for (j in 0 until n) {
            dist = Math.min(dist, Math.abs(a[j] - b[(i + j) % n]))
        }
        if (dist > maxv) {
            maxv = dist
            best = i
        }
    }

    var ans = Array<Int>(n) { -1 }
    for (i in 0 until n)
        ans[i] = (i + best) % n + 1
    println(ans.joinToString(" "))
}