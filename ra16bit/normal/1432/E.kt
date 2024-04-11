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
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt();
        var m = inp.nextLong();
        val s = inp.nextToken();
        var a = ArrayList<Char>();
        var cur = 0L;
        for (i in 0..n-1) if (s!!.get(i) == '0') {
            if (m >= cur) {
                m -= cur;
                a.add('0');
            } else {
                val rst = cur - m;
                for (j in 1..rst) a.add('1');
                a.add('0');
                cur -= rst;
                m = 0;
            }
        } else cur++;
        for (j in 1..cur) a.add('1');
        out.println(a.joinToString(separator=""){ x -> "${x}" });
    }
    out.close();
}