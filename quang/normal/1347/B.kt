import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var a1 = sc.nextInt();
        var b1 = sc.nextInt();
        var a2 = sc.nextInt();
        var b2 = sc.nextInt();
        if (a1 > b1) {
            var temp = a1;
            a1 = b1;
            b1 = temp;
        }
        if (a2 > b2) {
            var temp = a2;
            a2 = b2;
            b2 = temp;
        }
        println(if (b1 == b2 && a1 + a2 == b1) "YES" else "NO");
    }
}