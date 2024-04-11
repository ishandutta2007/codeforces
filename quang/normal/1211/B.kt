import java.util.*

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var a = Array(n) {0}
    for (i in 0..n - 1) {
        a[i] = sc.nextInt()
    }
    var maxPos = 0
    for (i in 1..n - 1) {
        if (a[i] >= a[maxPos]) {
            maxPos = i
        }
    }
    var u = (a[maxPos] - 1).toLong() * n + maxPos + 1
    println(u)
}