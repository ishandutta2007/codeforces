import java.io.InputStream
import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    repeat(n) {
        val x = nextInt().toLong()
        val y = nextInt().toLong()
        val b = minOf(x, y) - 1
        val a = x - b
        val c = y - b
        println("$a $b $c")
    }
}