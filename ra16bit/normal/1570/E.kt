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
    val tt = inp.nextInt();
    for (t in 1..tt) {
        var s = inp.nextToken();
        var n = s!!.length
        var cnt = 0;
        var mn = n;
        var mx = 0;
        for (i in 0..n - 1) if (s!![i] == '1') {
            ++cnt;
            mn = Math.min(mn, i);
            mx = i;
        }
        if (cnt == 0) out.println(0); else out.println(mx - mn + 1 - cnt);
    }
    out.close();
}