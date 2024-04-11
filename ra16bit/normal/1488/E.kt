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

class SumTree(n: Int) {
    var b = Array(size = 4*n, init = { i -> 1 });

    fun set(i:Int, L:Int, R:Int, pos:Int, v:Int) {
        if (L==R) {
            b[i]=v;
            return;
        }
        var h=(L+R)/2
        if (pos<=h) set(i*2,L,h,pos,v); else set(i*2+1,h+1,R,pos,v)
        b[i]=max(b[i*2],b[i*2+1]);
    }

    fun fnd(i:Int, L:Int, R:Int, le:Int, ri:Int): Int {
        if (L==le && R==ri) return b[i];
        var h=(L+R)/2;
        var cur=0;
        if (le<=h) cur=fnd(i*2,L,h,le,min(ri,h));
        if (ri>h) cur=max(cur,fnd(i*2+1,h+1,R,max(h+1,le),ri))
        return cur;
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt()
        val a = Array(n, { i -> inp.nextInt() });
        var prv = Array(n+1, { i -> -1 });
        var segtree = SumTree(n);
        var res = 1
        for (i in 0..n-1) {
            if (prv[a[i]]!=-1) {
                if (prv[a[i]]+1==i) {
                    segtree.set(1,0,n-1,prv[a[i]],2)
                    res = max(res, 2)
                } else {
                    var cur = segtree.fnd(1,0,n-1,prv[a[i]]+1,i-1) + 2
                    segtree.set(1,0,n-1,prv[a[i]],cur)
                    res = max(res, cur)
                }
            } else prv[a[i]]=i
        };
        out.println(res);
    }
    out.close();
}