import java.io.InputStream
import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    var max1 = 0
    var max2 = 0
    var cnt = 0
    repeat(n) {
        val a = nextInt()
        if (a < max1 && a < max2) {
            cnt = cnt + 1
        }
        if (a > max2)
            max2 = a
        if (max2 > max1) {
            max1 = max2.also { max2 = max1 }
        }
    }
    println(cnt)
}