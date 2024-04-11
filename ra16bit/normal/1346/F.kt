import java.util.*
import java.io.*
import java.lang.Long.min

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
    val tt=1
    for (t in 1..tt) {
        val n = inp.nextInt();
        val m = inp.nextInt();
        val q = inp.nextInt();
        var a = Array(n*m, { i-> inp.nextLong()});
        var b = Array(n, { i-> 0L})
        var c = Array(m, { i-> 0L})
        for (i in 0..n-1) for (j in 0..m-1) {
            val pos = i*m+j;
            b[i]+=a[pos];
            c[j]+=a[pos];
        }
        out.print(solve(b)+solve(c));
        for (i in 1..q) {
            val x = inp.nextInt() - 1;
            val y = inp.nextInt() - 1;
            val pos = x*m + y;
            b[x]-=a[pos];
            c[y]-=a[pos];
            a[pos]=inp.nextLong();
            b[x]+=a[pos];
            c[y]+=a[pos];
            out.print(' ')
            out.print(solve(b)+solve(c));
        }
    }
    out.close();
}

fun solve(b: Array<Long>): Long {
    val n = b.size;
    var s = Array(n, {i -> 0L});
    var cur = 0L;
    var cnt = 0L;
    for (i in n-1 downTo 0) {
        s[i]=cur;
        cnt += b[i];
        cur += cnt;
    }
    var res = cur;
    cur = 0L;
    cnt = 0L;
    for (i in 0..n-1) {
        res = min(res, cur + s[i])
        cnt += b[i];
        cur += cnt;
    }
    return res
}