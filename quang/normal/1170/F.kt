import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.max
import kotlin.math.min

var n = 0
var m = 0
var k = 0
var a = Array(0) {0}
var sum = Array(0) {0L}

fun main() {
    val sc = Scanner(System.`in`)
    n = sc.nextInt()
    m = sc.nextInt()
    k = sc.nextInt()
    a = Array(n + 1) {0}
    sum = Array(n + 1){0L}

    for (i in 1..n) {
        a[i] = sc.nextInt()
    }
    a.sort()
    for (i in 1..n) {
        sum[i] = sum[i - 1] + a[i]
    }

    var res = 1000000000000000000L
    var need = (m + 1) / 2
    for (i in 1..n) {
        var low = max(0, i - need)
        var high = i
        while (high - low > 1) {
            var mid = (low + high) / 2
            var tot = 1L * a[i] * (i - mid + 1)
            tot -= (sum[i] - sum[mid - 1])
            if (tot <= k) high = mid
            else low = mid
        }
        var tot = 1L * a[i] * (i - low) - (sum[i] - sum[low])
        var rest = m - (i - low)

        var fixedPoint = 1L * a[i]
        if ((i - low) < rest && i < n) {
            var canGo = (k - tot) / (i - low)
            fixedPoint = min(1L * a[i + 1], a[i] + canGo)
            tot += (fixedPoint - a[i]) * (i - low)
        }

        if (i + rest > n) continue
        tot += sum[i + rest] - sum[i]
        tot -= fixedPoint * rest

        res = min(res, tot)
    }
    println(res)
}