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
    var n = inp.nextInt()
    var a = Array(n, { i -> inp.nextInt() })
    val MX = 200200;
    var c = Array(MX, { i -> 0 })
    for (i in 0..n-1) ++c[a[i]];
    var was = false;
    for (i in 0..MX-1) if (c[i]>2) was=true;
    if (!was) {
        out.println("YES")
        var cnt=0
        for (i in 0..MX-1) if (c[i]>0) ++cnt;
        out.println(cnt);
        cnt=0;
        for (i in 0..MX-1) if (c[i]>0) {
            out.print("${i} ");
            --c[i];
            if (c[i]>0) ++cnt;
        }
        out.println()
        out.println(cnt);
        for (i in MX-1 downTo 0) if (c[i]>0) out.print("${i} ");
    } else out.println("NO");
    out.close();
}