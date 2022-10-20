import java.util.*
import kotlin.collections.ArrayList

var nxt = Array(0) {0}
var used = Array(0) {0}
var n = 0

fun getNext(u : Int) : Int {
    if (u == n + 1) return u
    if (used[u] == 0) return u
    var res = getNext(nxt[u])
    nxt[u] = res
    return res
}

fun main() {
    val sc = Scanner(System.`in`)
    var m = sc.nextInt()
    var a = Array(m + 1) {0}
    n = 0
    for (i in 1..m) {
        a[i] = sc.nextInt()
        if (a[i] == -1) n++
    }

    var res = Array(n + 1) {ArrayList<Int>()}
    nxt = Array(n + 1) {0}
    used = Array(n + 1) {0}

    for (i in 1..n) nxt[i] = i + 1
    var now = 1
    var dead = 0
    while (dead < n) {
        var cur = getNext(1)
        while (cur <= n) {
            if (a[now] == -1) {
                used[cur] = 1
                dead++
            } else {
                res[cur].add(a[now])
            }
            now++
            cur = getNext(nxt[cur])
        }
    }
    println(n)
    for (i in 1..n) {
        print("${res[i].size} ")
        for (u in res[i]) print("$u ")
        println("")
    }
}