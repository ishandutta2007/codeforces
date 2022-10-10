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
    val n = inp.nextInt();
    val m = inp.nextInt();
    val a = Array(n+1, { i-> Array(m+1, {j->0})})
    val f = Array(n+1, { i-> Array(m+1, {j->0})})
    for (i in 0..n-1) {
        val s = inp.nextToken()
        for (j in 0..m-1) a[i+1][j+1]=s!![j]-'A'
    }
    var b = Array(32, {i->0})
    var cnt = Array(32, {i->0L})
    var st = Array(m+2, {i->0})
    var v = Array(m+2, {i->0})
    for (msk in 1..31) {
        for (i in 1..n) {
            var top = 0
            var sum = 0L
            for (j in 1..m) {
                if (((msk shr a[i][j]) and 1)==1) f[i][j]=f[i-1][j]+1; else f[i][j]=0;
                while (top>0 && f[i][j]<=v[top]) {
                    sum -= v[top]*(st[top]-st[top-1])
                    --top
                };
                ++top
                v[top] = f[i][j]
                st[top] = j
                sum += v[top]*(st[top]-st[top-1])
                cnt[msk] += sum
            }
        }
        for (prv in 1..msk-1) if ((prv and msk)==prv) {
            cnt[msk] -= cnt[prv]
            b[msk]=Math.max(b[msk],b[prv])
        }
        ++b[msk]
    }
    for (i in 1..5) {
        var cur=0L
        for (msk in 1..31) if (b[msk]==i) cur+=cnt[msk]
        out.print("$cur ")
    }
    out.close();
}