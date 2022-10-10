import java.util.*
import java.io.*
import java.lang.Integer.max

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
        var r = 0L
        val a = Array(n, { i->inp.nextLong() })
        for (i in 0..n-1) {
            var cnt=0L
            for (j in 0..n-1) if (a[j]>=a[i]) ++cnt
            r=Math.max(r,cnt*a[i])
        }
        out.println(r);
    }
    out.close();
}