import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt();
        var k = sc.nextInt();
        var x = sc.nextInt();
        var y = sc.nextInt();
        var a = Array<Int>(n, {0});
        var sum = 0.toLong();
        for (i in a.indices) {
            a[i] = sc.nextInt();
            sum += a[i];
        }
        a.sort();
//        for (i in 0 until a.size) print("${a[i]} ");
//        println();
        var res = (1e18).toLong();

        var now = 0.toLong();
        for (element in a) {
            if (element > k) now += x;
        }
        res = min(res, now);
        now = 0.toLong();
        for (i in a.size - 1 downTo 0) {
            if (sum > k.toLong() * n.toLong()) {
                now += x;
                sum -= a[i];
            }
        }
        now += y;
        res = min(res, now);
        println(res);
    }
}