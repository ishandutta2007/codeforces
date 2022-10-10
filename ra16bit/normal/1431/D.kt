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
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt()
        val a = Array(n, { i -> inp.nextInt() })
        val k = Array(n, { i -> i })
        var r = Array(n, { i -> 0 })
        Arrays.sort(k, Comparator {
            x: Int, y: Int -> if (a[x] < a[y]) -1 else if (a[x] == a[y]) 0 else 1
        })
        var cnt = 0
        var le=0
        var ri=n-1
        for (i in 0..n-1) if (a[k[le]] <= cnt) {
            cnt=1
            r[i] = k[le]+1
            ++le
        } else {
            ++cnt
            r[i] = k[ri]+1
            --ri
        };
        for (i in 0..n-1) out.print("${r[i]} ")
        out.println();
    }
    out.close();
}