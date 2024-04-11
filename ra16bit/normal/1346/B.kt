import java.util.*
import java.io.*
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
        val x = inp.nextInt();
        val y = inp.nextInt();
        val s = inp.nextToken();
        var a = Array(n, { i-> 0});
        var r=0;
        for (i in 0..n-1) if (s!!.get(i)=='1') {
            a[i]=x;
            if (i>0) a[i]=min(a[i],y-a[i-1]);
            r += a[i];
        }
        out.println(r);
    }
    out.close();
}