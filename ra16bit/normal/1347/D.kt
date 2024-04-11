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
        val n = inp.nextInt();
        val a = Array(n, { i -> inp.nextInt() });
        var i = 0;
        var j = n-1;
        var x = 0
        var y = 0;
        var cur = 0;
        var prv = 0;
        while (i <= j) {
            var now = 0;
            if (cur % 2 == 0) {
                while ((i <= j) and (now <= prv)) {
                    now += a[i];
                    i += 1;
                }
                x += now;
            } else {
                while ((i <= j) and (now <= prv)) {
                    now += a[j];
                    j -= 1
                };
                y += now;
            }
            prv = now;
            cur += 1;
        }
        out.println("$cur $x $y");
    }
    out.close();
}