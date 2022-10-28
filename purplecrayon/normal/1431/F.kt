import kotlin.math.max;
import kotlin.math.min;
import kotlin.math.abs;
import java.util.*;


private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun valid(a: List<Long>, k: Int, x: Int, v: Long): Boolean {
    var num_deleted = 0;
    var cur = 0;
    var n = a.size;
    while (cur < n) {
        var nxt = cur + x;
        
        val max_comparator: Comparator<Long> = compareBy { -it };
        val vals = PriorityQueue<Long>(max_comparator);

        var sm = 0L;
        for (i in cur until min(n, nxt)) {
            sm += a[i];
            vals.add(a[i]);
        }
        while (sm > v) {
            if (num_deleted >= k) return false;
            
            var mx = vals.peek();
            vals.remove(mx);
            sm -= mx;
            num_deleted++;
            
            if (nxt < n) {
                var y = a[nxt];
                vals.add(y);
                sm += y;
                nxt++;
            }
        }
        cur = nxt;
    }
    return true;
}
fun main() {
    val INF = 1000000000000000000L;

    var (n, k, x) = readInts();
    var a = readLongs();
    var lo = -1L;
    var hi = INF;
    var mid = (lo+hi)/2;
    
   
   /*
    var ans = valid(a, k, x, 18);
    println(ans);
    */
    
    while (lo < mid && mid < hi) {
        if (valid(a, k, x, mid)) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    
    println(hi);
}