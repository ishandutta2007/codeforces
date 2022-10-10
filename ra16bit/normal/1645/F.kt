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
    var a = Array(n, { i -> inp.nextInt() })
    a.sort()
    var r = 0
    for (i in 0..n-1) {
        if (a[i]>1 && (i==0 || a[i-1]<a[i]-1)) --a[i];
          else if (i>0 && a[i]<=a[i-1]) ++a[i];
        if (i==0 || a[i]!=a[i-1]) ++r
    }
    out.println(r)
    out.close()
}