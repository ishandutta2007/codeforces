import java.io.InputStream
import java.util.*

fun main() = with(Scanner(System.`in`)) {
    val n = nextInt()
    nextLine()
    repeat(n) {
        val s = nextLine()
        val t = nextLine()
        val n = s.length    
        val m = t.length
        var it = 0
        var ok = 1
        for (c in t) {
            if (it == n) {
                ok = 0
                break
            }
            if (c == s.get(it)) {
                it += 1
                continue
            }
            if (c == '+' && it < n - 1 && s.get(it) == '-' && s.get(it + 1) == '-') {
                it += 2
                continue
            }
            ok = 0
            break
        }
        if (ok == 1 && it == n)
            println("YES")
        else
            println("NO")
    }
}