import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt();
    for (t in 1..tc) {
        var n = sc.nextInt();
        var k1 = sc.nextInt();
        var k2 = sc.nextInt();
        var s = sc.next().toCharArray();
        if (k1 * 2 <= k2) {
            var cnt = 0;
            for (u in s) {
                if (u == '1') cnt++;
            }
            println(k1.toLong() * cnt.toLong());
        } else {
            var res = 0.toLong();
            var last = -1;
            for (i in 0 until n) {
                if (s[i] == '0') {
                    var num = i - last - 1;
                    res += k2.toLong() * (num / 2).toLong();
                    if (num % 2 == 1) {
                        res += k1;
                    }
                    last = i;
                }
            }
            var num = n - last - 1;
            res += k2.toLong() * (num / 2).toLong();
            if (num % 2 == 1) {
                res += k1;
            }
            println(res);
        }
    }
}