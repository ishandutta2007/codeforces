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
    for (tc in 0 until t) {
        var n = readInt()
        var color = readInts()
        var target = readInts()
        var graph = Array<ArrayList<Int>>(n, {ArrayList<Int>()})
        for (i in 0 until n - 1) {
            var (a, b) = readInts()
            a--
            b--
            graph[a].add(b)
            graph[b].add(a)
        }
        var bads = ArrayList<Int>()
        for (i in 0 until n) {
            if (color[i] != target[i]) {
                bads.add(i)
            }
        }

        if (bads.size == 0) {
            println("Yes")
            println(0)
            continue
        }

        if (bads.size == 1) {
            println("No")
            continue
        }

//        System.err.println("here")

        var tin = IntArray(n)
        var tout = IntArray(n)
        var tcnt = 0
        var parent = IntArray(n)

        fun dfs(v: Int, p: Int) {
            tin[v] = tcnt
            ++tcnt
            for (to in graph[v]) {
                if (to != p) {
                    dfs(to, v)
                    parent[to] = v
                }
            }
            tout[v] = tcnt
            ++tcnt
        }

        dfs(0, 0)

//        for (i in 0 until n) {
//            System.err.println(tin[i].toString() + " " + tout[i].toString())
//        }

        fun is_parent(par: Int, v: Int): Boolean {
            return tin[par] <= tin[v] && tout[v] <= tout[par]
        }

        fun get_lca(a: Int, b: Int): Int {
            if (is_parent(a, b)) {
                return a
            }
            var tmp = b
            while (!is_parent(tmp, a)) {
                tmp = parent[tmp]
            }
            return tmp
        }

//        System.err.println(bads)

        var lv = bads[0]
        var rv = bads[0]
        for (v in bads) {
            if (tout[v] < tout[lv]) {
                lv = v
            }
            if (tin[v] > tin[rv]) {
                rv = v
            }
        }

        var lca = get_lca(lv, rv)

        if (lv == rv) {
            for (v in bads) {
                if (tin[v] < tin[lca]) {
                    lca = v
                }
            }
            lv = lca
        }

//        System.err.println(lv.toString() + " " + rv.toString() + " " + lca.toString())

        var ok = true
        for (v in bads) {
            if (!(is_parent(v, lv) && is_parent(lca, v)) && !(is_parent(v, rv) && is_parent(lca, v))) {
                ok = false
                break
            }
        }

        if (!ok) {
            println("No")
            continue
        }

        var path = ArrayList<Int>()
        while (!is_parent(lv, rv)) {
            path.add(lv)
            lv = parent[lv]
        }
        path.add(lv)
        var tmp_path = ArrayList<Int>()
        while (rv != lv) {
            tmp_path.add(rv)
            rv = parent[rv]
        }
        tmp_path.reverse()
        for (v in tmp_path) {
            path.add(v)
        }

//        System.err.println(path)

        var found = false
        for (tr in 0 until 2) {
            var cok = true
            for (i in 0 until path.size - 1) {
                var v = path[i]
                var next = path[i + 1]
                if (target[v] != color[next]) {
                    cok = false
                    break
                }
            }
            if (cok) {
                if (target[path.last()] == color[path[0]]) {
                    found = true
                    println("Yes")
                    println(path.size)
                    println(path.map { it + 1 }.joinToString(separator = " "))
                    break
                }
            }
            path.reverse()
        }
        if (!found) {
            println("No")
        }
    }
}