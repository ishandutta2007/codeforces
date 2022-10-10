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

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val tt = inp.nextInt();
    for (t in 1..tt) {
        var n = inp.nextInt();
        val k = inp.nextInt();
        var s = inp.nextToken()
        var a = Array(n,{i->(s!![i]-'0')})
        var m = 0
        for (i in 0..n-1) if (a[i]==1) m++;
        if (m==0) { out.println(0); continue; }
        var pos = 0
        var res = 0;
        while (true) {
            ++res
            if (a[pos]==1) --m
            if (m<=0) break;
            --n;
            for (j in pos..n-1) a[j]=a[j+1]
            pos = (pos + k - 1)%n
        }
        out.println(res)
    }
    out.close();
}