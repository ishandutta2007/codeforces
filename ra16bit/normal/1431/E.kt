import java.util.*
import java.io.*
import java.lang.Integer.max
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
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt()
        val a = Array(n, { i -> inp.nextInt() })
        val b = Array(n, { i -> inp.nextInt() })
        var r=-1;
        var w=0;
        for (i in 1..n) {
            var st=n-i;
            var cur=Math.abs(b[st]-a[0]);
            for (j in 0..i-1) cur=Math.min(cur,Math.abs(b[st+j]-a[j]))
            for (j in i..n-1) cur=Math.min(cur,Math.abs(a[j]-b[j-i]))
            if(cur>r) { r=cur; w=i; }
        }
        var st=n-w;
        for (i in 0..w-1) {
            out.print(st+i+1)
            out.print(' ')
        }
        for (i in w..n-1) {
            out.print(i-w+1)
            out.print(' ')
        }
        out.println()
    }
    out.close();
}