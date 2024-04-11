import java.util.*
import java.io.*
import java.lang.Integer.max

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
    val n = inp.nextInt()
    val m = inp.nextInt()
    val a = Array(n, { i -> inp.nextInt() })
    Arrays.sort(a)
    val f = Array(n, { i -> Array(n, { j -> 0 }) })
    for (len in 1..n-1) if (len%2==1) for (i in 0..n-1) {
        val j=i+len
        if (j>=n) break;
        f[i][j]=a[j]-a[i];
        if (i+1<j) f[i][j]+=f[i+1][j-1]
        for (k in i+1..j-2) if (k%2==j%2) {
            f[i][j]=Math.max(f[i][j],f[i][k]+f[k+1][j])
        }
    }
    val dp = Array(n+1, { i -> Array(m+1, { j -> 0 }) })
    for (i in 1..n) for (j in 0..m) if (j*2<=i) {
        dp[i][j] = dp[i-1][j]
        for (k in 1..j) {
            dp[i][j] = Math.max(dp[i][j], dp[i-k*2][j-k] + f[i-k*2][i-1])
        }
    }
    out.println(dp[n][m]);
    out.close();
}