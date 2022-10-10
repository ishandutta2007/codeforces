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
        val x = inp.nextLong();
        var y = inp.nextLong();
        var z = x;
        var r = 0L;
        while (z<=y) z*=10;
        while (z>=x) {
            val cur=y/z;
            r+=cur;
            y-=cur*z;
            z/=10;
        }
        out.println(y + r);
    }
    out.close();
}