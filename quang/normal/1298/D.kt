import java.util.*
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var n = sc.nextInt()
    var w = sc.nextInt()
    var minVal = 0;
    var maxVal = 0
    var cur = 0
    for (i in 0 until n) {
        var u = sc.nextInt()
        cur += u
        minVal = min(minVal, cur)
        maxVal = max(maxVal, cur)
    }
    var res = max(0, w - maxVal + minVal + 1)
    println(res)
}