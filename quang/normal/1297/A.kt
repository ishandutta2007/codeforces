import java.util.*
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt()
        if (n < 1000) println(n)
        else if (n < 1000000) {
            var cur = n / 1000
            if (n % 1000 >= 500) cur++
            if (cur == 1000) {
                println("1M")
            } else
            println("${cur}K")
        } else {
            var cur = n / 1000000
            if (n % 1000000 >= 500000) cur++
            println("${cur}M")
        }
    }
}