import java.util.*
import kotlin.system.exitProcess

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

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

class comp<T: Comparable<T>>: Comparator<Array<T>> {
    override fun compare(o1: Array<T>, o2: Array<T>): Int {
        for (i in o1.indices)
            if (o1[i] != o2[i]) return if (o1[i] < o2[i]) -1 else 1
        return 0
    }
}

fun main() {
    var (n, m) = arrayOf(getInt(), getInt())
    var g = MutableList(n + 1) { MutableList(0) { Pair(0, 0) } }

    for (i in 0 until m) {
        var (u,v,w) = readLine()!!.split(" ").map{ it.toInt() }
        g[u].add(Pair(v, w))
        g[v].add(Pair(u, w))
    }

    val MAXW = 50
    var dist = MutableList(n + 1) { Long.MAX_VALUE }
    var pq = PriorityQueue<Array<Long>>(comp())
    var done = MutableList(n + 1) { false }
    var pot = MutableList(n + 1) { MAXW + 7 }

    dist[1] = 0
    pq.add(arrayOf(0, 1))
    while (!pq.isEmpty()) {
        var (_, u) = pq.poll().map{ it.toInt() }

        if (done[u])
            continue
        done[u] = true

        for ((mid, w) in g[u]) {
            if (pot[mid] <= w)
                continue
            pot[mid] = w

            for ((v, w2) in g[mid]) {
                if (dist[v] > dist[u] + (w + w2) * (w + w2)) {
                    dist[v] = dist[u] + (w + w2) * (w + w2)
                    pq.add(arrayOf(dist[v], v.toLong()))
                }
            }
        }
    }

    var sb = StringBuilder()
    for (u in 1 .. n)
        sb.append("${if (dist[u] == Long.MAX_VALUE) -1 else dist[u]} ")

    println(sb.toString())
}