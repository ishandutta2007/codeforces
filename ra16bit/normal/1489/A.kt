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
    val a = Array(n, { i -> inp.nextInt() });
    var b = Array(n, { i -> true });
    var lst = Array(1010, { i -> -1 });
    var ans = n;
    for (i in 0..n-1) {
        if (lst[a[i]] >= 0) {
            b[lst[a[i]]] = false;
            ans -= 1;
        }
        lst[a[i]] = i;
    }
    out.println(ans);
    for (i in 0..n-1) if (b[i]) out.print("${a[i]} ");
    out.println();
    out.close();
}