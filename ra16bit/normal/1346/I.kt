import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
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

class Path {
    var score : Long = 0;
    var len : Long = 0;

    constructor(score: Long, len: Long) {
        this.score = score
        this.len = len
    }
}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val n = inp.nextInt()
    val m = inp.nextInt()
    val q = inp.nextInt()
    val s = inp.nextInt() - 1
    val a = Array(n, { i->inp.nextInt() })
    val inf = 1000000000000000000L
    var g = Array(n, { i-> Array(n, { j -> inf })})
    for (i in 0..n-1) g[i][i] = 0
    for (i in 1..m) {
        val x = inp.nextInt() - 1
        val y = inp.nextInt() - 1
        g[x][y] = 1
    }
    for (k in 0..n-1) for (i in 0..n-1) for (j in 0..n-1)
        g[i][j] = Math.min(g[i][j], g[i][k] + g[k][j])
    val MSK = (1 shl n) - 1;
    var c = Array(MSK + 1, { i-> 0L })
    for (msk in 0..MSK) for (j in 0..n-1) if (((msk shr j) and 1) == 1) {
        c[msk] = c[msk xor (1 shl j)] + a[j]
        break
    }
    var f = Array(MSK + 1, { i-> Array(n, { j -> Array(n, { k -> inf })})})
    for (i in 0..n-1) f[(1 shl i)][i][i]=0;
    val p = Array(n, { i -> arrayListOf<Path>() })
    for (msk in 0..MSK) for (j in 0..n-1) for (k in 0..n-1) if (f[msk][j][k] < inf) {
        p[j].add(Path(c[msk], f[msk][j][k]))
        // out.println("f $msk $j $k = ${f[msk][j][k]}")
        for (nxt in 0..n-1) if (((msk shr nxt) and 1) == 0) {
            val nmsk = msk xor (1 shl nxt);
            f[nmsk][j][nxt] = Math.min(f[nmsk][j][nxt], f[msk][j][k] + g[k][nxt])
        }
    }
    var dp = Array(50, { i -> Array(n, { j -> Array(n, { k -> inf }) })})
    for (i in 0..n-1) for (j in 0..n-1) dp[0][i][j]=f[MSK][i][j]
    for (z in 1..49) for (i in 0..n-1) for (j in 0..n-1) for (k in 0..n - 1)
        dp[z][i][j] = Math.min(dp[z][i][j], dp[z - 1][i][k] + dp[z - 1][k][j])
    for (i in 0..n-1) {
        Collections.sort(p[i], Comparator {
            a: Path, b: Path -> if (a.score < b.score) -1 else if (a.score === b.score) 0 else 1
        })
        for (j in p[i].size-2 downTo 0) {
            val prv = p[i].get(j+1).len
            if (prv < p[i].get(j).len) {
                p[i].set(j, Path(p[i].get(j).score, prv))
            }
        }
    }
    for (qq in 1..q) {
        var v = inp.nextLong()
        val cnt = v / c[MSK]
        v -= cnt * c[MSK]
        var res = Array(n, { i -> inf })
        res[s] = 0
        for (i in 49 downTo 0) if (((cnt shr i) and 1L) == 1L) {
            var nxt = Array(n, { i -> inf })
            for (j in 0..n-1) for (k in 0..n-1)
                nxt[k] = Math.min(nxt[k], res[j] + dp[i][j][k])
            for (j in 0..n-1) res[j] = nxt[j]
        }
        var ans = inf
        for (i in 0..n-1) if (p[i].size>0){
            if (p[i].get(p[i].size-1).score < v) continue
            var le=0
            var ri=p[i].size - 1
            while (le < ri) {
                val mid = (le + ri) / 2
                if (p[i][mid].score >= v) ri=mid; else le = mid + 1
            }
            ans = Math.min(ans, res[i] + p[i][ri].len)
            //for (j in 0..n-1) for (msk in 0..MSK) if (c[msk] >= v) ans = Math.min(ans, res[i] + f[msk][i][j])
        }
        out.println(ans)
    }
    out.close()
}