import java.util.*

fun main(args: Array<String>) = with(Scanner(System.`in`)){
    val n = nextInt()
    val a = IntArray(n) { nextInt() }
    var max1 = Int.MIN_VALUE
    var max2 = Int.MIN_VALUE
    var ans = 0
    for (x in a) {
        if (max1 > x && max2 > x) ans++
        if (x > max1) {
            max2 = max1
            max1 = x
        } else if (x > max2) {
            max2 = x
        }
    }
    println(ans)
}