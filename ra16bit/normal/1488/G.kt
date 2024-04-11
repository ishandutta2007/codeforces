import java.util.*
import java.io.*
import java.lang.Integer.max
import java.lang.Integer.min
import java.lang.Math.abs
import kotlin.collections.ArrayList

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

fun rec(l:Int, cur:Int, lst:Int, c:Array<Int>, d:ArrayList<Pair<Int,Int>>, s:TreeSet<Pair<Int,Int>>) {
    if (l == d.size) {
        if (cur<lst) {
            var p=Pair<Int, Int>(c[cur], cur);
            if (s.contains(p)) {
                s.remove(p)
                --c[cur];
                s.add(Pair<Int, Int>(c[cur], cur))
            }
        }
        return
    }
    var now = cur
    for (i in 0..d.get(l).second) {
        rec(l+1,now,lst,c,d,s)
        now*=d.get(l).first;
    }
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val a = Array(n+1, { i -> 0 });
    val c = Array(n+1, { i -> 0 });
    c[1]=1
    for (i in 2..n) if (a[i]==0) {
        var j = i;
        while (j<=n) {
            a[j]=i;
            j+=i;
        }
        c[i]=2;
    } else {
        var j = i
        c[i] = 1
        while (a[j] == a[i]) {
            j /= a[j]
            ++c[i];
        }
        c[i] *= c[j]
    }
    val comparator = Comparator {
        x: Pair<Int,Int>, y: Pair<Int,Int> ->
        if (x.first != y.first) x.first.compareTo(y.first) else x.second.compareTo(y.second)
    }

    var s = TreeSet<Pair<Int,Int>>(comparator)
    for (i in 1..n) {
        --c[i];
        s.add(Pair<Int,Int>(c[i],i))
    }
    var res = 0L
    for (i in 2..n) {
        var cur = s.last()
        s.remove(cur)
        //out.println("cur = ${cur.first};${cur.second}")
        //out.flush();
        res += cur.first
        out.print("${res} ")
        var d = ArrayList<Pair<Int,Int>>();
        var j = cur.second
        while (j > 1) {
            var dv = a[j]
            var cnt = 0
            while (a[j]==dv) {
                j/=a[j]
                ++cnt
            }
            d.add(Pair<Int,Int>(dv,cnt))
        }
        rec(0,1,cur.second,c,d,s)
    }
    out.println(0)
    out.close();
}