import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    while (tc > 0) {
        tc--
        var n = sc.nextInt()
        var a = Array(n) {0}
        for (i in 0 until n) a[i] = sc.nextInt()
        var order = Array(n){0}
        for (i in 0 until n) order[i] = i
        //sort
        order.sortWith(object: Comparator<Int>{
            override fun compare(p1: Int, p2: Int): Int {
                return a[p1] - a[p2];
            }
        })
        var res = Array(n){0}
        var l = 0
        var r = n - 1
        var cur = 0
        for (i in 0 until n) {
            if (cur >= a[order[l]]) {
                res[i] = order[l];
                l++
                cur = 1
            } else {
                res[i] = order[r];
                r--;
                cur++
            }
        }
        for (u in res) print("${u + 1} ")
        println("")
    }
}