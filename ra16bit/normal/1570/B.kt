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
    val a = inp.nextInt();
    val b = inp.nextInt();
    val x = inp.nextInt();
    val y = inp.nextInt();
    val n = inp.nextInt();
    var mn = a+b;
    var mx = 0;
    for (i in 0..a*x) {
        val m = n - i;
        if (m<0 || m>y*b) continue;
        var cur = Math.max(0,i-(x-1)*a) + Math.max(0, m-(y-1)*b);
        mn=Math.min(mn,cur);
        cur = i/x + m/y;
        mx=Math.max(mx,cur);
    }
    println("$mn $mx");
    out.close();
}