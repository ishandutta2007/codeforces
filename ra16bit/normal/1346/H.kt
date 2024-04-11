import java.util.*
import java.io.*
import java.lang.Integer.min
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
    val MX = 2000100;
    var al = Array(n, {i->0})
    var ar = Array(n, {i->0})
    var c = Array(MX, { i-> arrayListOf<Int>()})
    for (i in 0..n-1) {
        al[i] = inp.nextInt()
        ar[i] = inp.nextInt()
    }
    for (i in 0..m-1) {
        val bl = inp.nextInt()
        val br = inp.nextInt()
        c[bl+br].add(br-bl)
    }
    for (i in 0..MX-1) if (c[i].size > 0) c[i].sort()
    for (i in 0..n-1) {
        var res = MX
        val cur = al[i] + ar[i]
        var len = ar[i]-al[i]
        if (c[cur].size > 0) {
            var pos = c[cur].binarySearch(len)
            if (pos < 0) pos = -(pos+2)
            if (pos>=0) res=min(res,(len-c[cur][pos])/2)
        }
        if ((cur-2>=0) && (cur+2<MX)) {
            if ((c[cur-2].size > 0) && (c[cur+2].size > 0)) {
                var posa = c[cur-2].binarySearch(len - 2)
                if (posa < 0) posa = -(posa+2)
                var posb = c[cur+2].binarySearch(len - 2)
                if (posb < 0) posb = -(posb+2)
                if ((posa>=0) && (posb>=0)) {
                    res=min(res,max((len-c[cur-2][posa])/2,(len-c[cur+2][posb])/2))
                }
            }
        }
        if (res==MX) out.print(-1); else out.print(res)
        out.print(' ')
    }

    out.close()
}