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
        val n = inp.nextInt();
        val k = inp.nextInt();
        val x = 1 + k + k * k + k * k * k;
        val f = n / x;
        out.print(f);
        out.print(' ');
        out.print(f*k);
        out.print(' ');
        out.print(f*k*k);
        out.print(' ');
        out.println(f*k*k*k);
    }
    out.close();
}