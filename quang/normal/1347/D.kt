import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt();
        var dq = ArrayDeque<Int>();
        for (i in 1..n) {
            var u = sc.nextInt();
            dq.addLast(u);
        }
        var last = 0;
        var curPlayer = 0;
        var moves = 0;
        var a = 0;
        var b = 0;
        while (dq.isNotEmpty()) {
            moves++;
            var sum = 0;
            if (curPlayer == 0) {
                while (sum <= last && dq.isNotEmpty()) {
                    sum += dq.first;
                    dq.removeFirst();
                }
                a += sum;
            } else {
                while (sum <= last && dq.isNotEmpty()) {
                    sum += dq.last;
                    dq.removeLast();
                }
                b += sum;
            }
            curPlayer = 1 - curPlayer;
            last = sum;
        }
        println("$moves $a $b");
    }
}