import java.util.*
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`);
    var tc = sc.nextInt();
    for (test in 1..tc) {
        var n = sc.nextInt();
        var k = sc.nextInt();
        var tot = 1 + k + k * k + k * k * k;
        var res = n / tot;
        println("${res} ${res * k} ${res * k * k} ${res * k * k * k}");
    }
}