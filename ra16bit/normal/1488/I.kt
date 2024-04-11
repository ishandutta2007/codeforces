import java.util.*
import java.io.*
import java.lang.Integer.max
import java.lang.Integer.min
import java.lang.Math.abs
import javax.management.MXBean

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

class Diniz() {
    val MX = 200200;
    val ME = MX * 6
    val INF = 1000000000

    var S = 0
    var T = 0
    var e = 0
    var tot = 0
    var g = Array(MX, { i -> ArrayList<Int>() });
    var dst = Array(MX, { i -> INF });
    //var pre = Array(MX, { i -> 0 });
    var ptr = Array(MX, { i -> 0 });
    var t = Array(ME, { i -> 0 });
    var f = Array(ME, { i -> 0 });
    var cap = Array(ME, { i -> 0 });

    fun addedge(fr: Int, to: Int, v: Int) {
        t[e] = to; f[e] = 0; cap[e] = v; g[fr].add(e++);
        t[e] = fr; f[e] = 0; cap[e] = 0; g[to].add(e++);
        assert(e<ME);
    }

    fun initialize(n: Int, m: Int, x: Array<Int>, y: Array<Int>, d: Array<Int>) {
        S = n + m;
        T = S + 1
        assert(T<MX)
        for (i in 0..m - 1) {
            var xc=x[i];
            var yc=y[i]
            if (d[yc] + 1 == d[xc]) {
                val tmp = xc
                xc = yc
                yc = tmp
            }
            if (d[xc] + 1 == d[yc]) {
                if (d[xc] % 2 == 0) {
                    addedge(S, i, 1)
                    addedge(i, m + xc, 1)
                    addedge(i, m + yc, 1)
                } else {
                    addedge(i, T, 1)
                    addedge(m + xc, i, 1)
                    addedge(m + yc, i, 1)
                }
            }
        }
    }

    fun dfs(i: Int, c: Int): Int {
        if (i == T) return c;
        while (ptr[i] < g[i].size) {
            var ed = g[i][ptr[i]];
            var k = t[ed];
            if (dst[k] == dst[i] + 1) {
                var fl = Math.min(c, cap[ed]-f[ed]);
                if (fl > 0) fl = dfs(k, fl);
                if (fl > 0) {
                    f[ed] += fl;
                    assert(((ed xor 1)==(ed+1) || (ed xor 1)==(ed-1)))
                    f[ed xor 1] -= fl;
                    return fl;
                }
            }
            ++ptr[i]
        }
        return 0;
    }

    fun pe(): Boolean {
        for (i in 0..T) dst[i] = INF;
        var q = ArrayList<Int>()
        q.add(S)
        dst[S] = 0;
        var fi = 0;
        while (fi < q.size) {
            var i = q.get(fi)
            ++fi
            for (ed in g[i]) if (f[ed]<cap[ed]) {
                var y = t[ed];
                if (dst[y] > dst[i] + 1) {
                    dst[y] = dst[i] + 1;
                    //pre[y] = ed
                    q.add(y)
                }
            }
            if (dst[T] < INF) return true;
        }
        return false;
    }

    fun solve(k:Int): Int {
        var tot=0
        while (pe() && tot<k) {
            for (i in 0..T) ptr[i] = 0;
            while (true) {
                var cur = dfs(S, k - tot)
                if (cur==0) break;
                tot += cur
            }
            /*var i=T
            while (i!=S) {
                ++f[pre[i]];
                --f[pre[i] xor 1];
                i=t[pre[i] xor 1];
            }
            ++tot*/
        }
        return tot
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val m = inp.nextInt()
    var k = inp.nextInt()
    k = Math.min(k,m/2)
    var g = Array(n, { i -> ArrayList<Int>() });
    var x = Array(m, { i -> 0 });
    var y = Array(m, { i -> 0 });
    for (i in 0..m-1) {
        x[i] = inp.nextInt()-1
        y[i] = inp.nextInt()-1
        g[x[i]].add(y[i])
        g[y[i]].add(x[i])
    }
    var diniz = Diniz()
    val inf=diniz.INF
    var dst=Array(n, {i -> inf})
    dst[0]=0
    var q = Array(n,{i->0})
    var fi = 0
    var fr = 1
    while (fi<fr) {
        var x=q[fi++]
        for (nxt in g[x]) if (dst[nxt]==inf) {
            dst[nxt]=dst[x]+1
            q[fr++]=nxt
        }
    }
    diniz.initialize(n,m,x,y,dst)
    out.println(diniz.solve(k))
    out.close();
}