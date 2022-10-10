import java.util.*
import java.io.*
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

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    var n = inp.nextInt()
    var sa = inp.nextToken()
    var sb = inp.nextToken()
    var a = Array(n, { i -> sa!![i]-'a' })
    var b = Array(n, { i -> sb!![i]-'a' })
    var s = Array(n, { i -> a[i]+b[i] })
    for (i in n-1 downTo 1) if (s[i]>=26) {
        s[i-1]+=s[i]/26;
        s[i]%=26;
    }
    for (i in 0..n-1) {
        var cur = s[i] / 2
        s[i] -= cur * 2
        if (i + 1 < n && s[i] > 0) s[i + 1] += s[i] * 26;
        out.print('a'.plus(cur))
    }
    out.close()
}