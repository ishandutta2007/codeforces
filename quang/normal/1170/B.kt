import java.util.*
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`)
    var n = sc.nextInt()
    var a = Array(n) {0}
    var x = 0
    var y = 0
    var res = 0
    for (i in 0..n - 1) {
        a[i] = sc.nextInt()
        if (a[i] < y) res++
        if (a[i] > y) {
            var temp = y
            y = a[i]
            a[i] = temp
        }
        if (y > x) {
            var temp = y
            y = x
            x = temp
        }
    }
    println(res)
}