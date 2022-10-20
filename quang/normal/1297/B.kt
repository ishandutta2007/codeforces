import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt()
        var a = Array<Pair<Int, Int>>(n) { Pair(0, 0) }
        var vals = ArrayList<Int>()
        for (i in 0 until a.size) {
            var l = sc.nextInt()
            var r = sc.nextInt()
            a[i] = Pair(l, r)
            vals.add(l)
            vals.add(r + 1)
        }
        var res = -1
        for (i in 0 until vals.size) {
            var u = vals[i]
            var cnt = 0
            for (j in 0 until a.size) {
                cnt += if (a[j].first <= u && u <= a[j].second) 1 else 0
            }
            if (res == -1 && cnt == 1) res = u
        }
        println(res)
    }
}