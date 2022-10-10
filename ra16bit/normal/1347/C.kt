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
        val s = inp.nextToken();
        var r = 0;
        for (i in 0..s!!.length-1) if (s[i]!='0') r++;
        out.println(r);
        for (i in 0..s!!.length-1) if (s[i]!='0') {
            val arr = Array(s!!.length - i, { x -> (if (x == 0) s[i] else '0') });
            out.print(arr.joinToString(separator=""){ x -> "${x}" });
            out.print(' ');
        }
        out.println(' ');
    }
    out.close();
}