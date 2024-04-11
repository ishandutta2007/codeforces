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

class comp : Comparator<Long> {
    override fun compare(o1: Long?, o2: Long?): Int {
        return o2!!.compareTo(o1!!)
    }
}

fun main() {
    var (n, k, x) = readInts()
    var ra = readLongs()
    var a = MutableList(n) { 0L }
    for (i in a.indices)
        a[i] = ra[i]

    for (i in 0 until x + 7)
        a.add(0)

    var l = 0L
    var r = 20_000_000_007L

    fun go(mid : Long) : Boolean {
        var pq = PriorityQueue<Long>(comp())
        var sum = 0L
        var rm = 0

        for (i in a) {
            pq.add(i)
            sum += i

            if (pq.size == x) {
                if (sum > mid) {
                    rm++
                    sum -= pq.remove()
                } else {
                    pq.clear()
                    sum = 0
                }
            }
        }

        return rm <= k
    }

    while (r > l) {
        var mid = (l + r) / 2

        if (go(mid)) {
            r = mid
        } else {
            l = mid + 1
        }
    }

    println(l)
}