import java.util.*
import java.io.*
import java.lang.Integer.max
import java.lang.Integer.min
import java.lang.Math.abs

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
        val n = inp.nextLong()
        val s = inp.nextLong()
        var l=(s+n-1L)/n;
        var r=s+1L
        while (l<r) {
            var h=(l+r)/2L+1L
            var cur=h
            var cnt=0
            var tot=0L
            while (cur>1 && cnt<n) {
                tot+=cur
                cur=(cur+1L)/2L
                ++cnt
            }
            if (cnt<n) tot += n-cnt;
            if (tot <= s) l=h; else r=h-1L;
        }
        out.println(r);
    }
    out.close();
}