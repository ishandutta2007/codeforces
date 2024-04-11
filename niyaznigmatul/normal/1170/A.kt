import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val n = nextInt()
    (1..n).forEach {
        val x = nextInt()
        val y = nextInt()
        val a = Math.min(x, y) - 1
        val b = x - a
        val c = y - a
        println("$a $b $c")
    }
}