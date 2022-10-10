import java.util.*
import java.io.*
import kotlin.collections.ArrayList

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
    var tt = inp.nextInt()
    for (t in 1..tt) {
        var n = inp.nextInt()
        var a = Array(n, { i -> inp.nextInt() })
        var x = a[0];
        var res = 0;
        for (i in 0..n - 1) for (j in i + 1..n - 1) if (a[i] == a[j]) x = a[i];
        for (i in 0..n - 1) if (a[i] != x) res = i+1;
        out.println(res);
    }
    out.close();
}