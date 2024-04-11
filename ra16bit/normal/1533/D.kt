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
    var n = inp.nextInt();
    val m = inp.nextInt();
    var b = Array(n*11, {i->Array<Int>(26, {j->0})})
    var c = Array(n*11, {i->0})
    var was = Array(n*11, {i->0})
    var num=0
    for (i in 0..n-1) {
        var s = inp.nextToken()
        var k = 0
        for (j in 0..m-1) {
            val cur=s!![j]-'a'
            if (b[k][cur]==0) b[k][cur]=++num;
            k=b[k][cur]
        }
        ++c[k]
    }
    var q=inp.nextInt()
    for (i in 1..q) {
        var s = inp.nextToken()
        var k = 0
        var r = 0
        for (j in 0..m) {
            var kk=k
            for (z in j+1..m) {
                val cur=s!![z]-'a'
                if (b[kk][cur]==0) { kk=-1; break; }
                kk=b[kk][cur]
            }
            if (kk>=0 && was[kk]!=i) {
                r += c[kk]
                was[kk]=i;
            }
            val cur=s!![j]-'a'
            if (b[k][cur]==0) break;
            k=b[k][cur]
        }
        out.println(r)
    }
    out.close();
}