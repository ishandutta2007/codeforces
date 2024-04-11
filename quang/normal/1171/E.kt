import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var n = sc.nextInt()
    var s = sc.next().toCharArray()
    s.sort()
    if (n == 1) {
        println("Yes")
        return
    }
    for (i in 0..n - 2) {
        if (s[i] == s[i + 1]) {
            println("Yes")
            return
        }
    }
    println("No")
}