import java.util.*
import java.io.*
import java.lang.Long.min

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
        val m = inp.nextLong();
        val x = inp.nextLong();
        val y = inp.nextLong();
        var a = Array(n, { i-> inp.nextLong()});
        var s = 0L;
        var oth = 0L;
        for (i in 0..n-1) {
            s+=a[i];
            if (a[i]>m) oth += 1;
        };
        if (oth == 0L) {
            out.println(0);
            continue;
        }
        if (s<=m*n) {
            out.println(min(y,x*oth));
            continue;
        }
        a.sort();
        var r=0L;
        for (i in n-1 downTo 0) {
            s-=a[i];
            r+=x;
            if (s<=m*n) {
                out.println(min(r+y,x*oth));
                break;
            }
        }
    }
    out.close();
}