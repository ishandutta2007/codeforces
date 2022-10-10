import java.util.*
import java.io.*
import java.lang.Integer.min

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
    val a = Array(n, { i -> inp.nextToken() });
    val k = Array(n, { i -> i });
    Arrays.sort(k, Comparator {
        x: Int, y: Int -> a[x]!!.length - a[y]!!.length;
    });
    var ok = true
    for (i in 1..n-1) if (ok) {
        var x = a[k[i-1]]!!;
        if (!a[k[i]]!!.contains(x)) {
            ok=false;
            break;
        }

    };
    if (ok) {
        out.println("YES");
        for (i in 0..n-1) out.println(a[k[i]])
    } else out.println("NO");
    out.close();
}