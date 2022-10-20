import java.lang.Math.max
import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    while (tc > 0) {
        tc--
        var n = sc.nextInt()
        var k = sc.nextInt()
        var a = Array(n + 1) {0}
        for (i in 1..n) a[i] = sc.nextInt()
        var res = 0
        for (i in n downTo 1) {
            var num = (n - i + 1) / k
            var tot = 0
            for (j in 0 until num) tot += a[i + j]
            res = max(res, tot)
        }
        println(res)
    }
}