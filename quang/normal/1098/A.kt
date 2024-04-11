import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.min

class Data(var l : Int = 0, var r : Int = 0, var id : Int = 0)
var res = 0L
var adj = Array(0) {ArrayList<Int>()}
var s = Array(0) {0}

fun dfs(u : Int, cur : Int) {
    if (res == -1L) return
    if (s[u] == -1) {
        var now = cur
        if (adj[u].isNotEmpty()) {
            now = 2000000000
            for (v in adj[u]) {
                now = min(now, s[v])
            }
        }
        if (cur > now) {
            res = -1
            return
        }
        res += now - cur
        for (v in adj[u]) {
            dfs(v, now)
        }
    } else {
        if (cur > s[u]) {
            res = -1
            return
        }
        res += s[u] - cur
        for (v in adj[u]) {
            dfs(v, s[u])
        }
    }
}

fun main() {
    val sc = Scanner(System.`in`)
    var n = sc.nextInt()
    adj = Array(n + 1) {ArrayList<Int>()}
    for (i in 2..n) {
        var u = sc.nextInt()
        adj[u].add(i)
    }
    s = Array(n + 1) {0}
    for (i in 1..n) {
        s[i] = sc.nextInt()
    }
    dfs(1, 0)
    println(res)
}