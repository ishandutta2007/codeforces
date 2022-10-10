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
        val n = s!!.length
        var a = false
        var b = false
        for (i in 0..n-1) {
            if (s!![i]=='<') a=true;
            if (s!![i]=='>') b=true;
        }
        if (a && b) out.println("?"); else if (a) out.println("<");
            else if (b) out.println(">"); else out.println("=");
    }
    out.close();
}