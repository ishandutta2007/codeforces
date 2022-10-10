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
    val n = inp.nextInt();
    val m = inp.nextInt();
    var a = Array(n, {i->Array(m, {j->inp.nextInt()})})
    var b = Array(n, {i->Array(m, {j->0})})
    var r = ArrayList<Pair<Int, Int>>()
    for (i in 0..n-2) for (j in 0..m-2)
        if (a[i][j]==1 && a[i+1][j]==1 && a[i][j+1]==1 && a[i+1][j+1]==1) {
            r.add(Pair(i+1,j+1))
            b[i][j]=1;
            b[i+1][j]=1;
            b[i][j+1]=1;
            b[i+1][j+1]=1;
        }
    var was = false;
    for (i in 0..n-1) for (j in 0..m-1) if (a[i][j]!=b[i][j]) {
        if (!was) out.println("-1");
        was=true
    }
    if (!was) {
        out.println(r.size)
        for (x in r) out.println("${x.first} ${x.second}");
    }
    out.close();
}