import java.util.*
import java.io.*
import kotlin.collections.ArrayList
import kotlin.collections.HashMap

class IOStream {
    val br = BufferedReader(InputStreamReader(System.`in`))
    var st: StringTokenizer? = null

    fun nextToken(): String? {
        while (st == null || !st!!.hasMoreTokens())
            st = StringTokenizer(br.readLine())
        return st!!.nextToken()
    }

    fun nextInt(): Int {
        return nextToken()!!.toInt()
    }

    fun nextLong(): Long {
        return nextToken()!!.toLong()
    }
}

class StrChecker {
    fun check(a: Array<String?>, r: Array<Char>, value: String): Boolean {
        val n = value.length
        val m = a.size
        for (i in 0..m-1) r[i] = 'A';
        for (i in 1..n-1) {
            var v = value.substring(0,i);
            var ok = false
            for (j in 0..m-1) if (r[j] == 'A' && a[j].equals(v)) {
                r[j] = 'P';
                ok = true
                break
            }
            if (!ok) return false
        }
        for (i in 1..n-1) {
            var v = value.substring(i,n);
            var ok = false
            for (j in 0..m-1) if (r[j] == 'A' && a[j].equals(v)) {
                r[j] = 'S';
                ok = true
                break
            }
            if (!ok) return false
        }
        return true;
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt();
    val m = 2*n-2;
    var sc = StrChecker();
    var a = Array(m, { i-> inp.nextToken()});
    var r = Array(m, { i -> 'A' });
    var pos = Array(2, {i->0})
    var len = 0
    for (i in 0..m-1) if (a[i]!!.length == n-1) {
        pos[len] = i;
        len++
    }
    if (!sc.check(a, r,a[pos[0]] + a[pos[1]]!![n-2]))
        sc.check(a,r,a[pos[1]] + a[pos[0]]!![n-2]);
    for (i in 0..m-1) out.print(r[i]);
    out.println();
    out.close();
}