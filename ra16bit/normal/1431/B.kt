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
        val s = inp.nextToken()
        val n = s!!.length
        var r = 0
        var cnt = 0
        for (i in 0..n-1) if (s[i] == 'v') {
            ++cnt
            if (cnt >= 2) {
                cnt -= 2
                ++r
            }
        } else {
            ++r
            cnt = 0
        };
        out.println(r);
    }
    out.close();
}