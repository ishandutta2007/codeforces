import java.util.*
import kotlin.math.max

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    while (tc > 0) {
        tc--
        var n = sc.nextInt()
        var a = Array(n){0.toLong()}
        for (i in 0 until n) a[i] = sc.nextLong()
        a.sort()
        var res = 0.toLong()
        for (i in 0 until n) {
            res = max(res, (n - i).toLong() * a[i])
        }
        println(res)
    }
}