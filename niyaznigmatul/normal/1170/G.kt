import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints
private val br = BufferedReader(InputStreamReader(System.`in`))

private fun nextInt(): Int {
    var c = br.read()
    while (c <= 32) c = br.read()
    val neg = c == '-'.toInt()
    if (neg) c = br.read()
    var ans = 0
    while (c > 32) {
        ans = ans * 10 + c - '0'.toInt()
        c = br.read()
    }
    return when {
        neg -> -ans
        else -> ans
    }
}

fun main(args: Array<String>) {
    val n = nextInt()
    val m = nextInt()
    val edges = Array(n) { linkedSetOf<Int>() }
    val ans = mutableListOf<List<Int>>()
    for (x__ in 1..m) {
        val v = nextInt() - 1
        val u = nextInt() - 1
        if (v == u) {
            ans.add(listOf(v, v))
            continue
        }
        if (u in edges[v]) {
            edges[v].remove(u)
            edges[u].remove(v)
            ans.add(listOf(v, u, v))
        } else {
            edges[v].add(u)
            edges[u].add(v)
        }
    }
    for (e in edges) {
        if (e.size % 2 != 0) {
            println("NO")
            return
        }
    }
    val stack = IntArray(n)
    var sz = 0
    val was = BooleanArray(n)
    for (start in 0 until n) {
        if (edges[start].isEmpty()) continue
        stack[sz++] = start
        was[start] = true
        while (true) {
            val v = stack[sz - 1]
            if (edges[v].isEmpty()) {
                break
            }
            val u = edges[v].iterator().next()
            edges[v].remove(u)
            edges[u].remove(v)
            if (was[u]) {
                val curAns = mutableListOf(u)
                while (stack[sz - 1] != u) {
                    val d = stack[--sz]
                    was[d] = false
                    curAns.add(d)
                }
                curAns.add(u)
                ans.add(curAns)
                continue
            }
            was[u] = true
            stack[sz++] = u
        }
    }
    println("YES")
    println(ans.size)
    for (x in ans) {
        println("${x.size} ${x.map { it + 1 }.joinToString(" ")}")
    }
}