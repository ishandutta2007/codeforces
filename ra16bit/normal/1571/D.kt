import java.util.*
import java.io.*

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
    val n = inp.nextInt();
    val m = inp.nextInt();
    var a = Array(n, {i->Array(n, {j->0})})
    var b = Array(n, {i->0});
    var c = Array(n, {i->0});
    var sx=0;
    var sy=0;
    for (i in 1..m) {
        val x = inp.nextInt()-1;
        val y = inp.nextInt()-1;
        ++a[x][y];
        ++b[x];
        ++c[y];
        if (i==1) {
            sx=x;
            sy=y;
        }
    }
    var res=0;
    for (i in 0..n-1) for (j in 0..n-1) if (i!=j) {
        var cur=1;
        if (sx!=i) {
            if (sy!=j) {
                cur=b[i]+c[j]-a[i][j]+1;
            } else cur=a[i][j]+1;
        } else if (sy!=j) cur=a[i][j]+1;
        res=Math.max(res,cur);
    }
    out.println(res);
    out.close();
}