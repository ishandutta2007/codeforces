import java.util.*
import java.io.*
import java.lang.Integer.max

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
    val n = inp.nextInt()
    val m = inp.nextInt()
    val k = inp.nextInt()
    val a = Array(n, { i -> inp.nextLong() })
    val b = Array(m, { i -> inp.nextLong() })
    val c = Array(n, { i -> Array(m, { j-> inp.nextInt() }) })
    val best = Array(n, { i -> Array(m, { j-> c[i][j] }) })
    for (i in 0..n-1) for (j in 0..m-1) {
        if (i>0) best[i][j]=Math.max(best[i][j],best[i-1][j])
        if (j>0) best[i][j]=Math.max(best[i][j],best[i][j-1])
    }
    val inf = 1000000000000000L
    var i = 0
    var j = 0
    var num = 0
    val wi = Array(n + m + 1, { i->0 })
    val wj = Array(n + m + 1, { i->0 })
    val v = Array(n + m + 1, { i->0L })
    var st = 0
    while (i<n || j<m) {
        if (j>=m || (i<n && a[i]<b[j])) {
            wi[num]=i
            wj[num]=j-1
            v[num]=a[i]
            i++
        } else {
            wi[num]=i-1
            wj[num]=j
            v[num]=b[j]
            j++
        }
        if (v[num] == 0L) st=num
        num++
    }
    /*val f = Array(num, { i -> Array(2, { j-> inf }) })
    val z = Array(num, { i -> Array(2, { j-> inf }) })
    f[st][0]=0L
    z[st][0]=0L
    for (i in st..num-2) for (j in 0..1) if (f[i][j]<inf) {
        var cur = best[wi[i]][wj[i]]
        for (nxt in i+1..num-1) {
            val cnt = (v[nxt] - z[i][j] + cur - 1) / cur
            if (f[nxt][j] > f[i][j] + cnt) {
                f[nxt][j] = f[i][j] + cnt
                z[nxt][j] = z[i][j] + cur * cnt
            }
        }
        if (j==1) continue
        cur += k
        for (nxt in i+1..num-1) {
            val cnt = (v[nxt] - z[i][j] + cur - 1) / cur
            if (f[nxt][1] > f[i][j] + cnt) {
                f[nxt][1] = f[i][j] + cnt
                z[nxt][1] = z[i][j] + cur * cnt
            }
        }
    }
    out.println(Math.min(f[num-1][0],f[num-1][1]));
    }*/
    var r = inf
    for (i in st..num-1) {
        val cur = best[wi[i]][wj[i]] + k
        var cnt = 0L
        var pos = 0L
        for (j in st..i-1) {
            var now = best[wi[j]][wj[j]]
            var steps = (v[j+1] - pos + now - 1) / now
            cnt += steps
            pos += steps * now
        }
        for (j in i..num-2) {
            var now = Math.max(best[wi[j]][wj[j]], cur)
            var steps = (v[j+1] - pos + now - 1) / now
            cnt += steps
            pos += steps * now
        }
        r = Math.min(r, cnt)
    }
    out.println(r)
    out.close();
}