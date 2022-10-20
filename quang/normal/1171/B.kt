import java.util.*
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var a = sc.nextInt()
    var b = sc.nextInt()
    var c = sc.nextInt()
    b--
    c -= 2
    a = min(a, b)
    a = min(a, c)
    println(a * 3 + 3)
}