import java.util.*
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var a = Array<Int>(4){0}
    for (i in 0 until a.size) {
        a[i] = sc.nextInt()
    }
    a.sort()
    println("${a[3] - a[0]} ${a[3] - a[1]} ${a[3] - a[2]}")
}