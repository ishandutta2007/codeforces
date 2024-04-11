import java.util.*

fun main() {
    val scanner = Scanner(System.`in`)
    val t = scanner.nextInt()
    for (i in 0 until t) {
        val x = scanner.nextInt()
        val y = scanner.nextInt()
        if (x > y) {
            val c = 1
            val a = y - 1
            val b = x - a
            print(a)
            print(" ")
            print(b)
            print(" ")
            print(c)
            println()
        } else {
            val c = 1
            val a = x - 1
            val b = y - a
            print(a)
            print(" ")
            print(b)
            print(" ")
            print(c)
            println()
        }
    }
}