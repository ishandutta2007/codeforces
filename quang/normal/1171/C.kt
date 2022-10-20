import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (test in 1..tc) {
        var s = sc.next().toCharArray()
        s.sort()
        if (s[0] == s[s.size - 1]) {
            println(-1)
        } else {
            println(s)
        }
    }
}