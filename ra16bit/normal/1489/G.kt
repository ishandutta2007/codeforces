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

fun fs(x: Int, p: Array<Int>): Int {
    if (p[x]!=x) p[x] = fs(p[x],p);
    return p[x];
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt();
    val m = inp.nextInt();
    var a = Array(n, { i -> inp.nextLong() });
    var p = Array(n, { i -> i });
    var rk = Array(n, { i -> 0 });
    var best = Array(n, { i -> a[i] });
    var k = Array(m, { i -> i });
    var x = Array(m, { i -> 0 });
    var y = Array(m, { i -> 0 });
    var z = Array(m, { i -> 0L });
    for (i in 0..m - 1) {
        x[i] = inp.nextInt() - 1
        y[i] = inp.nextInt() - 1
        z[i] = inp.nextLong()
        k[i] = i;
    }
    Arrays.sort(k, Comparator { x: Int, y: Int ->
        z[x].compareTo(z[y]);
    });
    val comparator = compareBy<Pair<Long, Int>> { it.first }
    var q = PriorityQueue<Pair<Long, Int>>(comparator);
    for (i in 0..n - 1) {
        val p = Pair(best[i], i)
        q.add(p)
    };
    var j = 0
    var res = 0L
    while (q.size > 1) {
        if (j < m) {
            var pa = fs(x[k[j]], p);
            var pb = fs(y[k[j]], p);
            if (pa == pb) {
                ++j;
                continue;
            }
        }
        var a = q.remove();
        var b = q.remove();
        var pa = fs(a.second, p);
        var pb = fs(b.second, p);
        if (pa == pb) {
            q.add(a)
            continue;
        }
        if (j < m && z[k[j]] < a.first + b.first) {
            q.add(a);
            q.add(b);
            pa = fs(x[k[j]], p);
            pb = fs(y[k[j]], p);
            res += z[k[j]];
            ++j;
        } else res += a.first + b.first;
        if (rk[pa] >= rk[pb]) {
            p[pb] = pa;
            if (rk[pa] == rk[pb]) ++rk[pa];
            best[pa] = min(best[pa], best[pb]);
            q.add(Pair<Long, Int>(best[pa], pa))
        } else {
            p[pa] = pb;
            best[pb] = min(best[pa], best[pb]);
            q.add(Pair<Long, Int>(best[pb], pb))
        }
    }
    out.println(res);
    out.close();
}