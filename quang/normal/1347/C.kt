import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt();
        var cur = 1;
        var res = ArrayList<Int>();
        while (n > 0) {
            if (n % 10 != 0) {
                res.add((n % 10) * cur);
            }
            cur *= 10;
            n /= 10;
        }
        println(res.size);
        for (u in res) print("$u ");
        println("");
    }
}