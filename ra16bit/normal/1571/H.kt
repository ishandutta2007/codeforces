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

fun pw(a: Long, b: Int, md: Int) : Long {
    if (b==0) return 1L;
    if (b.and(1)==1) return (pw(a,b-1,md)*a)%md;
    val x = pw(a,b/2,md);
    return (x*x)%md;
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val a = inp.nextInt() * 2
    val b = inp.nextInt() * 2
    val md = 998244353
    val qq = 1000000L
    var x = Array(n,{i->0});
    var y = Array(n,{i->0});
    var pp = Array(n,{i->0L});
    for (i in 0..n-1) {
        x[i] = inp.nextInt() * 2
        y[i] = inp.nextInt() * 2
        pp[i] = qq - inp.nextInt()
    }
    var ca=0;
    var cb=0;
    var wasa =  Array(a+1,{i->false})
    var wasb =  Array(b+1,{i->false})
    for (i in 1..a-1) {
        for (j in 0..n-1) if (x[j]==i) wasa[i]=true;
        if (wasa[i]) ca++;
    }
    for (i in 1..b-1) {
        for (j in 0..n-1) if (y[j]==i) wasb[i]=true;
        if (wasb[i]) cb++;
    }
    var resP=(ca+1L)*(cb+1L);
    var resQ=1L;
    var dP = Array(a+b+1, {i -> 0L})
    var dQ = Array(a+b+1, {i -> 0L})
    for (i in 0..a+b) {
        var cnt = 0
        var prod = 1L;
        for (j in 0..n-1) if (x[j]+y[j]==i) {
            prod = (prod * pp[j]) % md;
            ++cnt;
        }

        dQ[i] = pw(qq,cnt,md);
        dP[i] = (dQ[i]+md-prod)%md;
        if (dP[i]>0) {
            var inner = 0;
            for (j in 1..a-1) for (k in 1..b-1)
                if (j + k == i && (wasa[j] || wasb[k])) ++inner;
            resP = ((((inner + 1L) * dP[i]) % md) * resQ + resP * dQ[i]) % md;
            resQ = (resQ * dQ[i]) % md
        }
    }
    var dP2 = Array(a+b+1, {i -> 0L})
    var dQ2 = Array(a+b+1, {i -> 0L})
    for (i in -b..a) {
        var cnt = 0
        var prod = 1L;
        for (j in 0..n-1) if (x[j]-y[j]==i) {
            prod = (prod * pp[j]) % md;
            ++cnt;
        }
        dQ2[b+i] = pw(qq,cnt,md);
        dP2[b+i] = (dQ2[b+i]+md-prod)%md;
        if (dP2[b+i]>0) {
            var inner = 0;
            for (j in 1..a-1) for (k in 1..b-1) if (j - k == i) {
                if (wasa[j] || wasb[k]) ++inner; else if (dP[j + k] > 0) {
                    resP = (((dP[j + k] * dP2[b + i]) % md) * resQ + ((resP * dQ2[b + i]) % md) * dQ[j + k]) % md
                    resQ = (((resQ * dQ2[b + i]) % md) * dQ[j + k]) % md
                }
            }
            resP = ((((inner+1L)*dP2[b+i])%md)*resQ+resP*dQ2[b+i])%md;
            resQ = (resQ*dQ2[b+i])%md
        }
    }
    out.println((resP*pw(resQ,md-2,md))%md);
    out.close();
}