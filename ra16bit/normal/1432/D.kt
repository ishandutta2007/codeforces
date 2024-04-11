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
        val a = inp.nextInt();
        val b = inp.nextInt();
        var s = ArrayList<Char>();
        for (i in 0..a-1) s.add('a' + min(i, b-1));
        for (i in a..n-1) s.add(s.get(i-a));
        out.println(s.joinToString(separator=""){ x -> "${x}" });
    }
    out.close();
}