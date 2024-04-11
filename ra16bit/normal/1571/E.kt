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
        val n = inp.nextInt()
        val s = inp.nextToken();
        val a = inp.nextToken();
        var ch = Array(16, {i->Array(4, {j->'('})})
        for (i in 0..15) for (j in 0..3) if (i.shr(j).and(1)==1) ch[i][j]=')';
        var dp = Array(n, {i->Array(16, {j->-1})})
        for (i in 0..15) if (a!![0]=='0' || i==10 || i==12) {
            var cnt=0;
            for (k in 0..3) if (s!![k]==ch[i][k]) ++cnt;
            dp[0][i]=cnt;
        }
        for (i in 0..n-5) for (j in 0..15) if (dp[i][j]>=0) {
            var nxt=j.shr(1).and(7);
            for (z in 1..2) {
                if (a!![i + 1] == '0' || nxt == 10 || nxt == 12) {
                    var add=0;
                    if (s!![i+4]==ch[nxt][3]) add=1;
                    dp[i+1][nxt]=Math.max(dp[i+1][nxt],dp[i][j]+add);
                }
                nxt+=8;
            }
        }
        var res=-1;
        for (j in 0..15) res=Math.max(res,dp[n-4][j]);
        if (res>=0) res=n-res;
        out.println(res);
    }
    out.close();
}