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

class MaxTree(n: Int) {
    var b = Array(size = 4 * n, init = { i -> 0L });

    fun upd(i: Int, L: Int, R: Int, pos: Int, v: Long) {
        if (L == R) {
            b[i] = Math.max(b[i],v);
            return;
        }
        var h = (L + R) / 2
        if (pos <= h) upd(i * 2, L, h, pos, v); else upd(i * 2 + 1, h + 1, R, pos, v)
        b[i] = Math.max(b[i * 2], b[i * 2 + 1]);
    }

    fun fnd(i: Int, L: Int, R: Int, le: Int, ri: Int): Long {
        if (L == le && R == ri) return b[i];
        var h = (L + R) / 2;
        var cur = 0L;
        if (le <= h) cur = fnd(i * 2, L, h, le, Math.min(ri, h));
        if (ri > h) cur = Math.max(cur, fnd(i * 2 + 1, h + 1, R, Math.max(h + 1, le), ri))
        return cur;
    }
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val m = inp.nextInt()
    var id = ArrayList<Int>()
    var a = ArrayList<Int>();
    var b = ArrayList<Int>();
    for (i in 0..n-1) {
        val cnt = inp.nextInt()
        for (j in 1..cnt) {
            id.add(i)
            a.add(0);
            b.add(0);
        }
        var curlen = b.size
        for (j in 1..cnt) {
            var x = inp.nextInt()
            a.set(curlen - j, x)
        }
        for (j in 1..cnt) {
            var x = inp.nextInt()
            b.set(curlen - j, x)
        }
    }
    var num = id.size
    var k = Array(num, { i->i });
    val comparator = Comparator {
            x: Int, y: Int ->
        if (b.get(x) != b.get(y)) b.get(y).compareTo(b.get(x)) else id.get(x).compareTo(id.get(y))
    }
    Arrays.sort(k, comparator);
    var segtree = MaxTree(n);
    for (ii in 0..num-1) {
        val i = k[ii]
        if (m-id.get(i)<=b.get(i)) {
            var d = id.get(i) - (m - b.get(i));
            var cur = a.get(i).toLong();
            if (d>0) cur += segtree.fnd(1,0,n-1, 0, d-1);
            segtree.upd(1,0,n-1,d,cur);
        }
    }
    out.println(segtree.b[1])
    out.close();
}