import java.util.*

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var a = Array(n) {Pair<Int, Int>(0, 0)}
    for (i in 0..n - 1) {
        var u = sc.nextInt()
        a[i] = Pair(u, i)
    }
    a.sortWith(object: Comparator<Pair<Int,Int>>{
        override fun compare(p1: Pair<Int, Int>, p2: Pair<Int, Int>): Int {
            if (p1.first != p2.first) return if (p1.first < p2.first) -1 else 1
            if (p1.second != p2.second) return if (p1.second < p2.second) -1 else 1
            return 0
        }
    })

    var cnt = 0
    var last = -1
    var res = Array(3){0}
    for (i in 0..n - 1) {
        if (a[i].first != last) {
            last = a[i].first
            res[cnt] = a[i].second + 1
            cnt++
        }
        if (cnt == 3) break
    }
    if (cnt == 3) {
        for (u in res) {
            print(u)
            print(" ")
        }
        println()
    } else println("-1 -1 -1")
}