import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    while (tc > 0) {
        tc--;
        var s = sc.next().toCharArray()
        var n = s.size
        var res = 0
        var cur = 0
        for (i in 0 until n) {
            if (s[i] == 'v') {
                cur++
            } else {
                res++
                res += cur / 2;
                cur = 0
            }
        }
        res += cur / 2
        println(res)
    }
}