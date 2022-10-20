import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt()
        var k = sc.nextInt()
        var a = Array<Int>(n){0}
        var id = Array<Int>(n){0}
        for (i in a.indices) {
            a[i] = sc.nextInt()
            id[i] = i
        }
        id.sortWith(object: Comparator<Int>{
            override fun compare(p1: Int, p2: Int): Int {
                if (a[p1] < a[p2]) return -1
                if (a[p1] > a[p2]) return 1
                return 0
            }
        })
        var low = -1
        var high = k + 1
        while (high - low > 1) {
            var mid = (low + high) / 2
            var cur = a[id[n - 1]] + mid
            var now = 0
            for (i in n - 1 downTo 0) {
                var foo = cur - a[id[i]]
                now += foo
                if (now >= k) break
                cur--
            }
            if (now < k) low = mid
            else high = mid
        }
        var res = Array<Int>(n){0}
        var cur = a[id[n - 1]] + high
        for (i in n - 1 downTo 0) {
            var now = cur - a[id[i]]
            now = min(now, k)
            k -= now
            res[id[i]] = now
            cur--
        }
        for (i in res.indices) print("${res[i]} ")
        println("")
    }
}