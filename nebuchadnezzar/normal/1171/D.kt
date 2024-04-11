import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

class Flow {
    class Edge(var c: Int) {
        var f = 0
    }

    var edges = ArrayList<Edge>()
    var graph = ArrayList<ArrayList<Pair<Int, Int>>>()

    fun addNode(): Int {
        graph.add(ArrayList<Pair<Int, Int>>())
        return graph.size - 1
    }

    fun addEdge(a: Int, b: Int, c: Int) {
        graph[a].add(Pair(b, edges.size));
        edges.add(Edge(c));
        graph[b].add(Pair(a, edges.size))
        edges.add(Edge(0))
    }

    var dist = IntArray(0)
    var vcnt = IntArray(0)
    var qu = IntArray(0)

    fun finishBuilding() {
        dist = IntArray(graph.size) {0}
        vcnt = IntArray(graph.size) {0}
        qu = IntArray(graph.size) {0}
    }

    fun buildLayers(s: Int, t: Int): Boolean {
        dist.fill(Int.MAX_VALUE);
        dist[s] = 0;
        var l = 0; var r = 0
        qu[r++] = s
        while (l < r) {
            var v = qu[l++]
            for (to in graph[v]) {
                if (edges[to.second].f < edges[to.second].c && dist[to.first] > dist[v] + 1) {
                    dist[to.first] = dist[v] + 1
                    qu[r++] = to.first
                }
            }
        }
        if (dist[t] == Int.MAX_VALUE) {
            return false
        }
        return true
    }

    fun pushFlow(v : Int, t : Int, f: Int): Int {
        if (v == t) {
            return f
        }
        while (vcnt[v] < graph[v].size) {
            var to = graph[v][vcnt[v]]
            if (edges[to.second].f < edges[to.second].c && dist[to.first] == dist[v] + 1) {
                var tmp = pushFlow(to.first, t, min(f, edges[to.second].c - edges[to.second].f));
                if (tmp > 0) {
                    edges[to.second].f += tmp
                    edges[to.second xor 1].f -= tmp
                    return tmp
                }
            }
            vcnt[v]++
        }
        return 0
    }

    fun pushWholeFlow(s: Int, t: Int): Int {
        var res = 0
        while (buildLayers(s, t)) {
            vcnt.fill(0);
            while (true) {
                var f = pushFlow(s, t, Int.MAX_VALUE);
                if (f == 0) {
                    break;
                }
                res += f
            }
        }
        return res
    }
}

fun main() {
    var (x, y, z) = readInts()
    var (a, b, c) = readInts()
    var f = Flow()
    var s = f.addNode()
    var t = f.addNode()
    var andrey = f.addNode()
    var dmitry = f.addNode()
    var mihail = f.addNode()
    f.addEdge(s, andrey, x)
    f.addEdge(s, dmitry, y)
    f.addEdge(s, mihail, z)
    var green = f.addNode()
    var purple = f.addNode()
    var black = f.addNode()
    f.addEdge(green, t, a)
    f.addEdge(purple, t, b)
    f.addEdge(black, t, c)
    f.addEdge(andrey, green, Int.MAX_VALUE)
    f.addEdge(dmitry, green, Int.MAX_VALUE)
    f.addEdge(dmitry, purple, Int.MAX_VALUE)
    f.addEdge(mihail, green, Int.MAX_VALUE)
    f.addEdge(mihail, purple, Int.MAX_VALUE)
    f.addEdge(mihail, black, Int.MAX_VALUE)
    f.finishBuilding()
    if (f.pushWholeFlow(s, t) == x + y + z) {
        println("YES")
    } else {
        println("NO")
    }
}