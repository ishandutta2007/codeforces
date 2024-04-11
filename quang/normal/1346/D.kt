import java.util.*
import kotlin.collections.ArrayList
import kotlin.math.*

class Edge(var u : Int = 0, var v : Int = 0, var w : Int = 0)

fun main() {
    val sc = Scanner(System.`in`)
    var tc = sc.nextInt()
    for (t in 1..tc) {
        var n = sc.nextInt();
        var m = sc.nextInt();
        var e = ArrayList<Edge>();
        var res = Array<Int>(n + 1, {0})
        e.add(Edge(0, 0, 0));
        for (i in 1..m) {
            var u = sc.nextInt();
            var v = sc.nextInt();
            var w = sc.nextInt();
            e.add(Edge(u, v, w));
            res[u] = max(res[u], w);
            res[v] = max(res[v], w);
        }

        var found : Boolean = false;
        for (i in 1..m) {
            var cur = min(res[e[i].u], res[e[i].v]);
            if (cur > e[i].w) {
                found = true;
                break;
            }
        }
        if (found) {
            println("NO");
        } else {
            println("YES");
            for (i in 1..n) print("${res[i]} ")
            println();
        }
    }
}