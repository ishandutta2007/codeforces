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
    val tt=1
    for (t in 1..tt) {
        val n = inp.nextInt();
        val m = inp.nextInt();
        val k = inp.nextInt();
        val inf = -1000000000;
        var a = Array(n, { i-> inf});
        a[k-1]=0;
        for (i in 0..m-1) {
            val x = inp.nextInt() - 1;
            val y = inp.nextInt() - 1;
            if (a[x] != inf) a[x] -= 1;
            if (a[y] != inf) a[y] -= 1;
            val vx = a[x];
            val vy = a[y];
            if (vx != inf) a[y]=max(a[y], vx+1);
            if (vy != inf) a[x]=max(a[x], vy+1);
        }
        for (i in 0..n-1) {
            if (a[i]!=inf) out.print(-a[i]); else out.print(-1);
            out.print(' ');
        }
        out.println();
    }
    out.close();
}