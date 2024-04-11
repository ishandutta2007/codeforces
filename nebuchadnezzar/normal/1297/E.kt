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
    for (i in 0 until t) {
        var (n, k) = readInts()
        var graph = Array<TreeSet<Int>>(n, {TreeSet<Int>()})
        for (i in 0 until n - 1) {
            var (a, b) = readInts()
            --a
            --b
            graph[a].add(b)
            graph[b].add(a)
        }

        if (k == 1) {
            println("Yes")
            println(1)
            println(1)
            continue
        }

        var leafs = TreeSet<Int>()
        var ans = TreeSet<Int>()
        for (j in 0 until n) {
            ans.add(j)
            if (graph[j].size == 1) {
                leafs.add(j)
            }
        }
        if (leafs.size < k) {
            println("No")
        } else {
            println("Yes")
            while (leafs.size > k) {
                var v = leafs.first()
                leafs.remove(v)
                ans.remove(v)
                for (to in graph[v]) {
                    graph[to].remove(v)
                    if (graph[to].size == 1) {
                        leafs.add(to)
                    }
                }
            }
            println(ans.size)
            for (v in ans) {
                print((v + 1).toString() + " ")
            }
            println()
        }
    }
}