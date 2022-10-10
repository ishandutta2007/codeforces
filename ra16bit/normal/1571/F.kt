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
    val n = inp.nextInt()
    val m = inp.nextInt()
    var a = ArrayList<Int>();
    var b = ArrayList<Int>();
    var idxa = ArrayList<Int>();
    var idxb = ArrayList<Int>();
    var tota=0;
    var totb=0;
    for (i in 1..n) {
        val x=inp.nextInt()
        val y=inp.nextInt()
        if (y==2) {
            tota+=x;
            a.add(x);
            idxa.add(i);
        } else {
            totb+=x;
            b.add(x);
            idxb.add(i);
        }
    }
    if (tota+totb<=m) {
        val len = a.size
        var dp = Array(len + 1, { i -> Array(tota + 1, { j -> false }) })
        dp[0][0] = true;
        for (i in 0..len - 1) for (j in 0..tota) if (dp[i][j]) {
            dp[i + 1][j] = true;
            dp[i + 1][j + a.get(i)] = true;
        }
        var ok = false;
        var r1 = ArrayList<Int>();
        var r2 = ArrayList<Int>();
        var len1 = ArrayList<Int>();
        var len2 = ArrayList<Int>();
        for (j in 0..tota) if (dp[len][j] && Math.max(tota, 2 * Math.max(j, tota - j) - 1) + totb <= m) {
            ok = true;
            var i = len;
            var jj = j;
            while (i>0) {
                if (dp[i-1][jj]) {
                    r1.add(idxa.get(i-1));
                    len1.add(a.get(i-1));
                } else {
                    r2.add(idxa.get(i-1));
                    len2.add(a.get(i-1));
                    jj-=a.get(i-1);
                }
                --i;
            }
            break;
        }
        if (ok) {
            if (r1.size < r2.size) {
                var rs = r1;
                r1=r2;
                r2=rs;
            }
            var res=Array(n+1,{i->0});
            var num1=1;
            var curlen=b.size;
            for (i in 0..curlen-1) {
                res[idxb.get(i)]=num1;
                num1+=b.get(i)
            };
            var num2=num1+1;
            curlen=r1.size;
            for (i in 0..curlen-1) {
                res[r1.get(i)]=num1;
                num1+=2*len1.get(i);
            }
            curlen=r2.size;
            for (i in 0..curlen-1) {
                res[r2.get(i)]=num2;
                num2+=2*len2.get(i);
            }
            for (i in 1..n) out.print("${res[i]} ");
            out.println();
        } else out.println(-1)
    } else out.println(-1);
    out.close();
}