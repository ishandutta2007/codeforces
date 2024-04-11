import java.util.*
import kotlin.math.*

class Data(var l : Int = 0, var r : Int = 0, var id : Int = 0)

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (test in 1..tc) {
        var n = sc.nextInt()
        var a = Array(n) {Data()}
        for (i in 0..n - 1) {
            a[i].l = sc.nextInt()
            a[i].r = sc.nextInt()
            a[i].id = i;
        }
        a.sortWith(object: Comparator<Data>{
            override fun compare(p1: Data, p2: Data): Int {
                if (p1.l != p2.l) return if (p1.l < p2.l) -1 else 1
                if (p1.r != p2.r) return if (p1.r < p2.r) -1 else 1
                return 0
            }
        })
        var cur = 0
        var pos = -1
        for (i in 0..n - 1) {
            if (i > 0 && cur < a[i].l) {
                pos = i
                break
            }
            cur = max(cur, a[i].r)
        }
        if (pos == -1) println(-1)
        else {
            var res = Array(n) {0}
            for (i in 0..n - 1) {
                res[a[i].id] = if (i < pos) 1 else 2
            }
            for (u in res) print("$u ")
            println("")
        }
    }
}