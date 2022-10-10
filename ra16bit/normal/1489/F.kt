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
    val m = inp.nextInt();
    val sz = inp.nextInt();
    var a = Array(n, { i -> inp.nextInt() });
    var f = Array(n + 1, { i -> 0 });
    var cur = 0;
    var rgh = n;
    var lst = n;
    for (i in n-1 downTo 0) {
        cur += a[i];
        while (cur > sz) {
            --rgh;
            cur -= a[rgh];
        }
        if (rgh <= i) break;
        f[i] = f[rgh] + 1;
        if (f[i] <= m) lst = i;
    }
    out.println(n - lst);
    out.close();
}