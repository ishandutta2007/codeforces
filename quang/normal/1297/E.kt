import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

var n : Int = 0
var k : Int = 0
var adj = Array(0){ArrayList<Int>()}
var res = ArrayList<Int>()
var numChild = Array<Int>(0){0}

fun dfs(u : Int, p : Int) {
    numChild[u] = if (adj[u].size == 1) 1 else 0
    for (i in 0 until adj[u].size) {
        var v = adj[u][i]
        if (v == p) continue
        dfs(v, u)
        numChild[u] += numChild[v]
    }
}

fun dfsRes(u : Int, p : Int, need : Int) {
    if (adj[u].size == 1) {
        res.add(u)
        k--
        return
    }
    var now = need
    if (now == 0) {
        var firstChild = if (adj[u][0] == p) adj[u][1] else adj[u][0]
        if (numChild[firstChild] < k) now = 1
//        println("firstChild $firstChild u $u now $now")
    }

    for (i in 0 until adj[u].size) {
        var v = adj[u][i]
        if (v == p) continue
        dfsRes(v, u, now)
        if (k == 0) break
    }

//    println("now $now u $u")
    if (now != 0) res.add(u)
}

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        n = sc.nextInt()
        k = sc.nextInt()
        res = ArrayList<Int>()
        numChild = Array<Int>(n + 1){0}
        adj = Array(n + 1){ArrayList<Int>()}
        for (i in 1..n-1) {
            var u = sc.nextInt()
            var v = sc.nextInt()
            adj[u].add(v)
            adj[v].add(u)
        }
        if (k == 1) {
            println("Yes")
            println(1)
            println(1)
        } else if (k == 2) {
            println("Yes")
            println(2)
            println("1 ${adj[1][0]}")
        } else {
            var root = -1
            for (i in 1..n) {
                if (adj[i].size > 1 && root == -1) root = i
            }
            dfs(root, 0)
            dfsRes(root, 0, 0)
            if (k > 0) {
                println("No")
            } else {
                println("Yes")
                println(res.size)
                for (i in res.indices) print("${res[i]} ")
                println("")
            }
        }
    }
}