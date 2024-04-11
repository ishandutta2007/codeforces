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
    val n = inp.nextInt();
    val s = inp.nextToken();
    var r = 0;
    var cnt = 0;
    for (i in 0..n-1) if (s?.get(i) == 'x') {
        ++cnt;
        if (cnt > 2) ++r;
    } else cnt = 0;
    out.println(r);
    out.close();
}