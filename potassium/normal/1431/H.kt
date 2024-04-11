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
    var (n, m, k) = readLongs()
    var a = readLongs()
    var b = readLongs()

    var c = Array<Array<Long>>(n.toInt()) { Array<Long>(m.toInt()) { 0 } }
    var mp = TreeMap<Long, Long>()
    for (i in c.indices) {
        var x = readLongs()
        for (j in c[i].indices) {
            c[i][j] = x[j]
            var req = Math.max(a[i], b[j])
            mp.put( req, Math.max(mp.getOrDefault(req, 0), x[j]) )
        }
    }

    val sz = mp.size
    var x = MutableList(0) { 0L }
    var y = MutableList(0) { 0L }
    for (i in mp.entries) {
        x.add(i.key)
        y.add(i.value)
    }

    for (i in 1 until sz)
        y[i] = Math.max(y[i], y[i - 1])

    fun go() : Long {
        var now = 0L
        var used = 0L
        var mov = 0L

        for (i in 0 until sz - 1) {
            mov = Math.max(mov, y[i])
            var nxt = x[i + 1]
            var dist = nxt - now

            if (dist <= 0)
                continue

            var take = (dist + mov - 1) / mov
            used += take
            now += take * mov
        }

        return used
    }

    var ans = Long.MAX_VALUE
    for (i in 0 until sz) {
        y[i] += k
        ans = Math.min(ans, go())
        y[i] -= k
    }

    println(ans)
}