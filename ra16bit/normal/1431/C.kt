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
        val m = inp.nextInt()
        val a = Array(n, { i -> inp.nextInt() })
        var r = 0
        for (cur in m..n) {
            val cnt = cur / m
            var sum = 0
            for (i in 0..cnt-1) sum += a[n-cur+i]
            r = Math.max(r, sum)
        }
        out.println(r);
    }
    out.close();
}