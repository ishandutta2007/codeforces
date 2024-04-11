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

val kotlin = "kotlin"

fun get_ind(c: Char) : Int {
    for (i in 0 until 6) {
        if (c == kotlin[i]) {
            return i
        }
    }
    return -1
}

fun main() {
    var n = readInt()
    var graph = Array<ArrayList<Pair<Int, Int>>>(6, {ArrayList<Pair<Int, Int>>()})
    var edges = ArrayList<Pair<Int, Int>>()
    for (i in 0 until n) {
        var cur = readLn()
        var from = get_ind(cur[0])
        var to = (get_ind(cur.last()) + 1) % 6
//        System.err.println(from.toString() + " " + to.toString())
        graph[from].add(Pair(to, i))
        edges.add(Pair(from, to))
    }

    var vcnt = IntArray(6)

    var ans = ArrayList<Int>()

    fun dfs(v : Int) {
//        System.err.println(v)
        while (vcnt[v] < graph[v].size) {
            var to = graph[v][vcnt[v]].first
            var e = graph[v][vcnt[v]].second
            ++vcnt[v]
            dfs(to)
            ans.add(e)
        }
    }

    dfs(0)
    ans.reverse()
//    System.err.println(ans)

    for (i in 0 until n) {
        if (edges[ans[i]].first == 0) {
            Collections.rotate(ans, -i)
            break
        }
    }

    println(ans.map { it + 1 }.joinToString(separator = " "))
}