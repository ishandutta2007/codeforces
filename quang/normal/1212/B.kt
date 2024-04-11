import java.util.*
import kotlin.collections.HashMap

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var s = sc.next()
    var res = 0
    var ans = String()
    var m = HashMap<String, Int>()
    for (i in 0..s.length - 2) {
        var now = s.substring(i, i + 2)
        var cnt = m.getOrDefault(now, 0) + 1
        m.put(now, cnt)
        if (res < cnt) {
            res = cnt;
            ans = now;
        }
    }
    println(ans)
}