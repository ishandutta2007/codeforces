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
    var b = Array(size = 4*n, init = { i -> 1 });
    var c = Array(size = 4*n, init = { i -> 0L })
    var lst = Array(size = 4*n, init = { i -> 0 })

    fun init(i:Int, L:Int, R:Int, a:Array<Int>) {
        var cur=a[R-1];
        lst[i]=cur;
        c[i]=cur.toLong();
        for (j in R-1 downTo L) {
            cur=max(cur,a[j-1])
            c[i]+=cur.toLong();
        }
        if (L==R) {
            b[i]=a[R-1];
            return;
        }
        var h=(L+R)/2
        init(i*2+1,h+1,R,a);
        init(i*2,L, h,a);
        b[i]=max(b[i*2],b[i*2+1]);
    }

    fun fnd(i:Int, L:Int, R:Int, le:Int, ri:Int, mx:Int): Pair<Long,Int> {
        if (L==le && R==ri && mx<=lst[i]) return Pair(c[i],b[i])
        if (mx>=b[i]) return Pair((ri-le+1L)*mx,mx);
        var h=(L+R)/2;
        if (ri>h) {
            if (le<=h) {
                var cur = fnd(i * 2 + 1, h + 1, R,h + 1, ri, mx)
                var nxt = fnd(i * 2, L,h, le, h, cur.second)
                return Pair(cur.first+nxt.first,nxt.second)
            }
            return fnd(i * 2 + 1, h + 1, R, le, ri, mx)
        }
        return fnd(i*2,L,h,le,ri,mx);
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val a = Array(n, { i -> inp.nextInt() });
    var segtree = SegTree(n);
    segtree.init(1,1,n,a)
    var q = inp.nextInt()
    while (q>0) {
        --q;
        val x = inp.nextInt()
        val y = inp.nextInt()
        out.print(segtree.fnd(1,1,n,x,y,0).first);
        if (q==0) out.println(); else out.print(' ')
    }
    out.close();
}