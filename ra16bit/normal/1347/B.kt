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
        val a = Array(2, { i -> inp.nextInt() });
        val b = Array(2, { i -> inp.nextInt() });
        var w = false;
        for (i in 0..1) for (j in 0..1) if (!w && a[i]==b[j] && a[i]==a[1-i]+b[1-j]) {
            out.println("Yes");
            w = true;
        }
        if (!w) out.println("No");
    }
    out.close();
}