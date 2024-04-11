import java.util.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

val MAX : Int = 400010

var n : Int = 0
var a = Array(0) {0}

fun check(maxVal : Int, n : Int, f : Int) : Boolean {
    var redArr = ArrayList<Int>()
    var greenArr = ArrayList<Int>()
    var flag = Array(n){-1}
    var h = HashMap<Int, Int>()
    for (i in 0 until n) {
        if (a[i] > maxVal) continue;
        var cnt = h.getOrDefault(a[i], 0)
        if (cnt == 0) {
            redArr.add(a[i])
            flag[i] = 0
        } else if (cnt == 1) {
            greenArr.add(a[i])
            flag[i] = 1
        } else return false
        h[a[i]] = cnt + 1
    }
    if (redArr.size != greenArr.size) return false
    if (redArr.size != maxVal) return false
    for (i in 0 until redArr.size) {
        if (redArr[i] != greenArr[i]) return false
    }
    if (f == 1) {
        for (i in 0 until n) {
            var u = if (flag[i] == -1) 'B' else if (flag[i] == 0) 'R' else 'G'
            print(u)
        }
        println()
    }
    return true
}

fun main() {
    val sc = Scanner(System.`in`);
    n = sc.nextInt()
    a = Array(n){0}
    for (i in 0 until n) {
        a[i] = sc.nextInt()
    }
    var low = -1
    var high = MAX
    while (high - low > 1) {
        var mid = (low + high) / 2
        if (check(mid, n, 0)) {
            low = mid
        } else {
            high = mid
        }
    }
    check(low, n, 1)
}