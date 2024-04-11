import java.util.*
import kotlin.collections.HashMap
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`);
    var n = sc.nextInt()
    var a = sc.nextInt()
    var b = sc.nextInt()
    var k = sc.nextInt()
    var r = Array(n){0}
    var m = HashMap<Int, Int>()
    for (i in 0..n - 1) {
        r[i] = sc.nextInt()
        var cnt = m.getOrDefault(r[i], 0) + 1
        m.put(r[i], cnt)
    }
    r.sort()
    if (a > b) {
        var res : Int = 0
        for (i in 0..n - 1) {
            var foo = m.getOrDefault(r[i], 0)
            var bar = m.getOrDefault(r[i] * k, 0)
            var now = min(foo / a , bar / b)
            res += now
            m.put(r[i], foo - now * a)
            m.put(r[i] * k, bar - now * b)
        }
        println(res)
    } else {
        var res : Int = 0
        for (i in n - 1 downTo 0) {
            if (r[i] % k != 0) continue
            var foo = m.getOrDefault(r[i], 0)
            var bar = m.getOrDefault(r[i] / k, 0)
            var now = min(foo / b , bar / a)
            res += now
            m.put(r[i], foo - now * b)
            m.put(r[i] / k, bar - now * a)
        }
        println(res)
    }
}