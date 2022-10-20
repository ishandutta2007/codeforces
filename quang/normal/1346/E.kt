import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.abs
import kotlin.math.min

fun main() {
    val sc = Scanner(System.`in`)
//    var tc = sc.nextInt()

    var tc = 1;
    for (t in 1..tc) {
        var n = sc.nextInt();
        var m = sc.nextInt();
        var k = sc.nextInt();
        var res = Array<Int>(n + 1) {n + 1};
        res[k] = 0;
        for (i in 1..m) {
            var x = sc.nextInt();
            var y = sc.nextInt();
            var newX = min(res[x] + 1, res[y]);
            var newY = min(res[y] + 1, res[x]);
            res[x] = newX;
            res[y] = newY;
        }
        for (i in 1..n) {
            if (res[i] <= n) print("${res[i]} ")
            else print("-1 ")
        }
        println()
    }
}