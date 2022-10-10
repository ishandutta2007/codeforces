import java.util.*
import java.io.*
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
        val n = inp.nextInt()
        val m = inp.nextInt()
        val s = inp.nextToken()
        var b = 0;
        var cnt = 0;
        var o = 0;
        for (i in 0..n-1) if (s!![i]==')'){
            --b;
            if (b==0) ++cnt; else ++o;
        } else {
            ++b;
        }
        out.println(cnt + min(o, m));
    }
    out.close();
}