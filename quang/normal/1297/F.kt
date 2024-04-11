import java.io.BufferedReader
import java.io.FileReader
import java.util.*
import kotlin.math.max


class Data(var l : Int = 0, var r : Int = 0, var id : Int = 0)

var n : Int = 0
var m : Int = 0
var a = Array(0){Data()}
var res = Array(0){0}
val INF = 2000000000
var ans : Int = 0

fun check(d : Int) : Boolean {
    var s = TreeSet<Long>()
    var curDay = -1
    var w = 0
    var cur = 0
    var cnt = 0
    while (true) {
        while (cur < n && a[cur].l <= curDay) {
            s.add((a[cur].r + d).toLong() * INF + a[cur].id)
            cur++
        }
        if (s.isEmpty()) {
            if (cur >= n) break
            curDay = a[cur].l
            w = 0
            continue
        }
        var now = s.first()
        s.remove(s.first())
        if (curDay > now / INF) {
            ans = max(ans, curDay - (now / INF).toInt())
        }
        res[(now % INF).toInt()] = curDay
        cnt++
        if (cnt == n) break
        w++
        if (w == m) {
            curDay++
            w = 0
        }
    }
    return true
}

fun main() {

    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        ans = 0
        n = sc.nextInt()
        m = sc.nextInt()
        a = Array(n){Data()}
        res = Array(n){0}
        for (i in 0 until n) {
            var l = sc.nextInt()
            var r = sc.nextInt()
            a[i] = Data(l, r, i)
        }
        a.sortWith(object: Comparator<Data>{
            override fun compare(p1: Data, p2: Data): Int {
                if (p1.l != p2.l) return if (p1.l < p2.l) -1 else 1
                if (p1.r != p2.r) return if (p1.r < p2.r) -1 else 1
                return 0
            }
        })
//        var low = -1
//        var high = 1000000000
//        while (high - low > 1) {
//            var mid = (low + high) / 2
//            if (check(mid)) high = mid
//            else low = mid
//        }
//        check(high)
        check(0)
        print("$ans\n")
        for (i in 0 until n) print("${res[i]} ")
        print("\n")
    }
}