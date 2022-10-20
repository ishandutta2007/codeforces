import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    while (tc > 0) {
        tc--
        var n = sc.nextInt()
        var a = Array(n) {0}
        for (i in 0 until n) a[i] = sc.nextInt()
        var orderA = Array(n){0}
        for (i in 0 until n) orderA[i] = i
        orderA.sortWith(object: Comparator<Int>{
            override fun compare(p1: Int, p2: Int): Int {
                return a[p1] - a[p2];
            }
        })

        var b = Array(n) {0}
        for (i in 0 until n) b[i] = sc.nextInt()
        var orderB = Array(n){0}
        for (i in 0 until n) orderB[i] = i
        orderB.sortWith(object: Comparator<Int>{
            override fun compare(p1: Int, p2: Int): Int {
                return b[p1] - b[p2];
            }
        })

        var res = Array(n){0}
        var ans = 0

        for (i in 0 until n) {
            var foo = Array(n){0}
            var minVal = 1000000000
            for (j in 0 until n) {
                foo[orderA[j]] = orderB[(j + i) % n]
                minVal = min(minVal, abs(a[orderA[j]] - b[orderB[(j + i) % n]]))
            }
            if (minVal > ans) {
                ans = minVal
                for (k in 0 until n) res[k] = foo[k]
            }
        }
        for (u in res) print("${u + 1} ")
        println("")
    }
}