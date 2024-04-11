import java.util.*
import java.io.*
import java.lang.Integer.min
import java.lang.Math.abs

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
        val n = inp.nextInt();
        if (n < 4) {
            out.println("-1");
            continue;
        }
        val mx=min(n,5);
        val msk=(1 shl mx);
        var f = Array(n, { i -> Array(msk, { x -> Array(mx, { y -> -1 })}) });
        for (i in 0..mx-1) if (i<n) f[mx-1][(1 shl (mx-1-i))][mx-1-i] = 0;
        for (i in 0..n-1) for (j in 0..msk-1) for (k in 0..mx-1) if (f[i][j][k] >= 0) {
            for (e in 0..mx-1) if ((abs(e-k)>1) and (abs(e-k)<5)) {
                val nj=(j or (1 shl e));
                if ((((j shr e) and 1) == 0) and (f[i][nj][e] == -1)) f[i][nj][e] = (((j shl 3) + k) shl 1);
            }
            if ((i + 1 < n) and (j>=msk/2) and (k<mx-1)) {
                var nj = ((j - msk/2) shl 1);
                if (f[i+1][nj][k+1] == -1) f[i+1][nj][k+1] = (((j shl 3) + k) shl 1) + 1;
                if ((k<4) and (k > 0)) {
                    nj = (nj or 1);
                    if (f[i+1][nj][0] == -1) f[i+1][nj][0] = (((j shl 3) + k) shl 1) + 1;
                }
            }
        }
        for (k in 0..mx-1) if (f[n-1][msk-1][k] >= 0) {
            var i = n-1;
            var j = msk-1;
            var e = k;
            var prv = n + 1;
            while (true) {
                if (i - e != prv) {
                    out.print(i - e + 1);
                    out.print(' ');
                    prv = i - e;
                }
                val value = f[i][j][e];
                if (value==0) break;
                i -= (value and 1);
                j = (value shr 4);
                e = ((value shr 1) and 7);
            }
            out.println();
            break;
        }
    }
    out.close();
}