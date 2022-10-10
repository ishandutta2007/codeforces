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
    var m = inp.nextInt();
    val d = inp.nextInt();
    var sum = d;
    val c = Array(m, { i -> inp.nextInt() });
    var s = Array(m+1, {i->0});
    var pos = Array(m+1, {i->0});
    for (i in 1..m) s[i] = s[i-1] + c[i-1];
    var prv = 0;
    for (i in 0..m-1) {
        pos[i] = min(n+1-(s[m]-s[i]), prv + d);
        prv = pos[i] + c[i] - 1;
    }
    if (prv + d > n) {
        out.println("YES");
        prv = 0;
        for (i in 0..m-1) {
            for (j in prv+1..pos[i]-1) out.print("0 ");
            prv = pos[i] + c[i] - 1;
            val cur = i + 1;
            for (j in pos[i]..prv) out.print("$cur ");
        }
        for (j in prv+1..n) out.print("0 ");
    } else out.println("NO");
    out.close();
}