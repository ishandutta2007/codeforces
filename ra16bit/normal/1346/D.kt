import java.util.*
import java.io.*
import java.lang.Integer.max
import java.lang.Integer.min

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

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt();
        val m = inp.nextInt();
        var a = Array(n, { i-> 0});
        var ex = Array(m, { i-> 0});
        var ey = Array(m, { i-> 0});
        var ez = Array(m, { i-> 0});
        for (i in 0..m-1) {
            ex[i] = inp.nextInt() - 1;
            ey[i] = inp.nextInt() - 1;
            ez[i] = inp.nextInt();
            a[ex[i]] = max(a[ex[i]], ez[i]);
            a[ey[i]] = max(a[ey[i]], ez[i]);
        }
        var ok = true;
        for (i in 0..m-1) if (min(a[ex[i]],a[ey[i]]) !=ez[i]) ok=false;
        if (ok) {
            out.println("YES");
            for (i in 0..n-1) {
                out.print(a[i]);
                out.print(' ');
            }
            out.println();
        } else out.println("NO");
    }
    out.close();
}