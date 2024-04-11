import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt()
        var a = Array<Int>(n){0}
        var sum = 0
        for (i in 0 until a.size) {
            a[i] = sc.nextInt()
        }
        var b = Array<Int>(n){0}
        for (i in 0 until a.size) {
            b[i] = if (a[i] > 0) 1 else 0
            if (a[i] > 0) sum += a[i]
        }
        var res = 1000000000
        var id = 0
        for (i in 0 until a.size) {
            if (abs(a[i]) < res && abs(a[i]) != 0) {
                res = abs(a[i])
                id = i
            }
        }
        b[id] = 1 - b[id]
        sum -= res
        println(sum)
        for (i in 0 until b.size) print(b[i])
        println("")
    }
}