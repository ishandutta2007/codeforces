import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.abs

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()

    var ar4 = arrayOf<Int>(2, 4, 1, 3);
    var ar5 = arrayOf<Int>(1, 3, 5, 2, 4);
    var ar6 = arrayOf<Int>(1, 3, 5, 2, 4, 6);
    var ar7 = arrayOf<Int>(1, 3, 5, 2, 6, 4, 7);

    for (t in 1..tc) {
        var n = sc.nextInt();
        if (n <= 3) {
            println(-1);
        } else {
            var res = ArrayList<Int>();
            var cur = 0;
            while (n >= 8) {
                for (u in ar4) {
                    res.add(cur + u);
                }
                cur += 4;
                n -= 4;
            }
            if (n == 4) for (u in ar4) res.add(cur + u);
            if (n == 5) for (u in ar5) res.add(cur + u);
            if (n == 6) for (u in ar6) res.add(cur + u);
            if (n == 7) for (u in ar7) res.add(cur + u);
            for (u in res) print("$u ");
            println()
        }
    }
}