import java.util.*
import kotlin.collections.ArrayList

var n = 0
var m = 0
var a = Array(0) {0}
var sum = Array(0) {0}

fun find(u : Int, cur : Int) : Int {
    var low = cur
    var high = n + 1
    while (high - low > 1) {
        var mid = (low + high) / 2
        var tot = sum[mid] - sum[cur]
        if (tot <= u) low = mid
        else high =mid
    }
    return low
}

fun main() {
    val sc = Scanner(System.`in`)
    n = sc.nextInt()
    m = sc.nextInt()
    a = Array(n + 1) {0}
    sum = Array(n + 1) {0}

    for (i in 1..n) {
        a[i] = sc.nextInt()
        sum[i] = sum[i - 1] + a[i]
    }

    var q = sc.nextInt()
    for (event in 1..q) {
        var c = sc.nextInt()
        var cur = 0
        var last = 0
        for (i in 1..c) {
            var w = sc.nextInt()
            cur = find(w - last - 1, cur)
//            println("$i $cur")
            last = w
        }
        cur = find(m - last, cur)
//        println("$cur")
        if (cur == n) println("YES")
        else println("NO")
    }
}