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
    val n = inp.nextInt();
    var a = Array(n, {i->inp.nextInt()})
    var k = Array(n, {i->i})
    Arrays.sort(k, Comparator { x: Int, y: Int ->
        (-a[x]).compareTo(-a[y]);
    });
    var r = 0;
    for (i in 0..n-1) r+=a[k[i]]*i+1;
    out.println(r);
    for (i in 0..n-1) out.print("${k[i]+1} ")
    out.close();
}