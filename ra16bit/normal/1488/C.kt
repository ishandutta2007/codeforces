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
        val n = inp.nextInt()
        var x = inp.nextInt()
        var y = inp.nextInt()
        if (x>y) {
            var z = x;
            x = y;
            y = z;
        }
        var len = max(x - 1, n - y)
        var res = 3 * n;
        for (i in x..y-1) {
            var lft = min(i-x + i-1, x-1 + i-1);
            var rgh = min(n-y + n-(i+1), y-(i+1) + n-(i+1));
            res = min(res, max(lft, rgh));
        }
        out.println(res);
    }
    out.close();
}