import java.util.*
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var k = sc.nextInt()
    var arr = Array(n) {Pair<Int, Int>(0, 0)}
    var res : Long = 0
    for (i in 0..n - 1) {
        var a = sc.nextInt()
        var b = sc.nextInt()
        var c = sc.nextInt()
        res += a.toLong() * c.toLong()
        k -= a
        arr[i] = Pair(c, b - a)
        if (k < 0) {
            println("-1")
            return
        }
    }
    if (k < 0) {
        println("-1")
        return
    }
    arr.sortWith(object: Comparator<Pair<Int,Int>>{
        override fun compare(p1: Pair<Int, Int>, p2: Pair<Int, Int>): Int {
            if (p1.first != p2.first) return if (p1.first < p2.first) -1 else 1
            if (p1.second != p2.second) return if (p1.second < p2.second) -1 else 1
            return 0
        }
    })
    for (u in arr) {
        var now = min(k, u.second)
        res += now.toLong() * u.first
        k -= now
    }
    if (k > 0) {
        println("-1")
        return
    }
    println(res)
}