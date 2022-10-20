import com.sun.jmx.remote.internal.ArrayQueue
import java.util.*
import kotlin.collections.ArrayList

var n = 0
var m = 0
var a = Array(0) {ArrayList<Int>()}
var res = Array(0) {ArrayList<Int>()}
var edges = ArrayList<Pair<Int, Int>>()
var removedEdges = Array(0){false}


fun getEdges(u : Int) : Int {
    while (a[u].isNotEmpty()) {
        var id = a[u][a[u].size - 1]
        a[u].removeAt(a[u].size - 1)
        if (removedEdges[id]) {
            continue
        }
        removedEdges[id] = true
        if (edges[id].first == u) return edges[id].second
        else return edges[id].first
    }
    return -1
}

fun main() {
    val sc = Scanner(System.`in`)
    n = sc.nextInt()
    m = sc.nextInt()
    a = Array(n + 1) {ArrayList<Int>() }
    res = Array(m + 1) {ArrayList<Int>() }

    var cur = 0
    for (i in 1..m) {
        var x = sc.nextInt()
        var y = sc.nextInt()
        if (x == y) {
            cur++
            res[cur].add(x)
            res[cur].add(x)
        } else {
            a[x].add(edges.size)
            a[y].add(edges.size)
            edges.add(Pair<Int, Int>(x, y))
        }
    }
    removedEdges = Array(edges.size){false}
    var found = 0
    for (i in 1..n) {
        if (a[i].size % 2 == 1) {
            found = 1
            break
        }
    }
    if (found == 1) {
        println("NO")
        return
    }

    var inQueue = Array(n + 1) {false}
    for (i in 1..n) {
        if (a[i].isEmpty()) continue
        var st = ArrayList<Int>()
        st.add(i)
        inQueue[i] = true
        while (st.isNotEmpty()) {
            var u = st[st.size - 1]
            var v = getEdges(u)
//            println("$u $v and")
//            for (x in st) print("$x ")
//            println()
//            for (i in 1..n) print("${inQueue[i]} ")
//            println()
            if (v == -1) {
                st.removeAt(st.size - 1)
                inQueue[u] = false
                continue
            }
            if (inQueue[v]) {
                cur++
                res[cur].add(v)
                while (true) {
                    var x = st[st.size - 1]
                    res[cur].add(x)
                    if (x == v) break
                    st.removeAt(st.size - 1)
                    inQueue[x] = false
                }
            } else {
                inQueue[v] = true
                st.add(v)
            }
        }
    }
    println("YES")
    println(cur)
    for (i in 1..cur) {
        print("${res[i].size} ")
        for (u in res[i]) print("$u ")
        println()
    }
}