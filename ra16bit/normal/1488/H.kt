import java.util.*
import java.io.*
import java.lang.Integer.max
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

class SegTree(n: Int) {
    val md = 998244353
    var c = Array(size = 4*n, init = { i -> Array(4) { j -> Array(4) { k -> 0 } } })

    fun solve(i: Int, h:Int, a:Array<Int>) {
        var eq = false
        if (a[h - 1] == 1) {
            if (h < a.size && a[h] == 1) eq=true;
        } else {
            if (h == a.size || a[h] == 0) eq=true;
        }
        for (j in 0..3) for (k in 0..3) {
            var nxt = 0L
            for (mid in 0..3) {
                var cur = c[i*2+1][mid][k].toLong()
                if (a[h - 1]==1) {
                    for (prv in 0 until mid) nxt = (nxt + cur*c[i*2][j][prv])%md
                } else {
                    for (prv in mid+1..3) nxt = (nxt + cur*c[i*2][j][prv])%md
                }
                if (eq) {
                    nxt = (nxt + cur * c[i*2][j][mid])%md
                }
            }
            c[i][j][k] = nxt.toInt()
        }
    }

    fun init(i:Int, L:Int, R:Int, a:Array<Int>) {
        if (L==R) {
            for (j in 0..3) c[i][j][j]=1;
            return;
        }
        var h=(L+R)/2
        init(i*2,L, h,a);
        init(i*2+1,h+1,R,a);
        solve(i,h,a)
    }

    fun mdfrgh(i:Int, L:Int, R:Int, a:Array<Int>) {
        if (L==R) return;
        var h=(L+R)/2;
        mdfrgh(i*2+1,h+1,R,a)
        solve(i,h,a);
    }

    fun mdf(i:Int, L:Int, R:Int, pos:Int, a:Array<Int>) {
        var h=(L+R)/2;
        if (pos<h) mdf(i*2,L,h,pos,a);
          else if (pos>h) mdf(i*2+1,h+1,R,pos,a)
            else mdfrgh(i*2,L,h,a);
        solve(i,h,a);
    }

    fun tot(): Int {
        var res = 0L
        for (j in 0..3) for (k in 0..3) res = (res + c[1][j][k])%md
        return res.toInt()
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    var q = inp.nextInt()
    var a = Array(n-1, { i -> inp.nextInt() });
    var segtree = SegTree(n);
    segtree.init(1,1,n,a)
    while (q>0) {
        --q;
        val x = inp.nextInt()
        if (a[x-1]==1) a[x-1]=0; else a[x-1]=1;
        segtree.mdf(1,1,n,x,a)
        out.println(segtree.tot());
    }
    out.close();
}