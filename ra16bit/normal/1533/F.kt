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
    val s = inp.nextToken();
    var n = s!!.length
    var z = Array(n, {i->0})
    var e = Array(n, {i->0})
    var wz = Array(n+2, {i->-1})
    var we = Array(n+2, {i->-1})
    if (s!![0]=='0') {
        ++z[0]
        wz[1]=0;
    } else {
        ++e[0]
        we[1]=0;
    };
    for (i in 1..n-1) {
        z[i]=z[i-1];
        e[i]=e[i-1];
        if (s!![i]=='0') {
            ++z[i]
            wz[z[i]]=i;
        } else {
            ++e[i]
            we[e[i]]=i;
        };
    }
    for (k in 1..n) {
        var r = 1
        var ce=0
        var cz=0
        while (we[ce+k+1]!=-1 && wz[cz+k+1]!=-1) {
            var pos = Math.max(we[ce+k+1],wz[cz+k+1])
            ce=e[pos-1];
            cz=z[pos-1];
            ++r;
        }
        out.print("$r ")
    }
    out.close();
}