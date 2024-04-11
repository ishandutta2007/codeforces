import java.util.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (test in 1..tc) {
        var s = sc.next().toCharArray()
        var t = sc.next().toCharArray()
        if (t.size > s.size) {
            println("NO")
            continue
        }
        var cur = 0
        var found = 0
        for (i in 0..t.size - 1) {
            if (cur >= s.size) {
                found = 1
                break
            }
            if (t[i] == s[cur]) {
                cur++
                continue
            }
            if (cur + 1 >= s.size) {
                found = 2
                break
            }
            if (t[i] == '-') {
                found = 3
                break
            }
            if (s[cur] == '+' || s[cur + 1] == '+') {
                found = 4
                break
            }
            cur += 2
        }
        if (found > 0 || cur != s.size) println("NO")
        else println("YES")
    }
}