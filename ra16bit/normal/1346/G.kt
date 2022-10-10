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
    val m = inp.nextInt()
    val n = inp.nextInt()
    var b = Array(m, { i-> inp.nextInt()})
    var a = Array(n, { i-> inp.nextInt()})
    val MX = 1000100
    var c = Array(MX, { i-> 0})
    for (i in 0..m-1) {
        var cur = b[i]
        if (c[cur] != 0) continue
        while (cur < MX) {
            c[cur] = b[i]
            cur += b[i]
        }
    }
    if (n==2) {
        var x=a[0]%b[0];
        var y=a[1]%b[0];
        var z=b[0];
        if (x==0) x=z;
        if (y==0) y=z;
        out.println("YES")
        out.println("$x $z");
        out.println("$y $z");
        out.close()
        return;
    }
    var found = false
    for (i in 0..m-1) {
        var ok = false
        var p = 0
        if (a[1]%b[i] == a[0]%b[i]) { ok = true; p = a[0]%b[i]; }
        if (n>2) {
            if (a[2]%b[i] == a[0]%b[i]) { ok = true; p = a[0] % b[i]; }
            if (a[2]%b[i] == a[1]%b[i]) { ok = true; p = a[1] % b[i]; }
        }
        if (!ok) continue
        var z = -1
        var e = -1
        var g = 0
        for (j in 0..n-1) if ((a[j]%b[i])!=p) {
            if (z==-1) { z=a[j]; continue; }
            if (e==-1) { g=a[j]-z; e=a[j]; continue; }
            g = gcd(a[j] - z, g)
            g = gcd(a[j] - e, g)
            e=a[j];
        }
        if ((g == 0) || (c[g] != 0)) {
            found = true
            if (p==0) p=b[i]
            var xp=p
            var wp=b[i]
            if (z>=0) {
                if (g>0) wp=c[g]
                xp=z%wp
                if (xp==0) xp=wp
            }
            var bad = false
            for (x in 0..n-1) if (((a[x]%b[i])!=(p%b[i])) && ((a[x]%wp)!=(xp%wp))) {
                bad = true
                break
            }
            if ((bad) || (p==0) || (wp==0)) continue
            out.println("YES")
            out.print("$p ")
            out.println(b[i])
            out.println("$xp $wp")
            break
        }
    }
    if (!found) out.println("NO")
    out.close()
}

fun gcd(a: Int, b: Int): Int {
    if (b==0) return a;
    return gcd(b,a%b);
}