import java.util.*
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (test in 1..tc) {
        var x = sc.nextInt()
        var y = sc.nextInt()
        var z = min(x, y) - 1
        println("$z ${x - z} ${y - z}")
    }
}