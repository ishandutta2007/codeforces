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
    val q = inp.nextInt();
    var w = Array(200200, { i -> 0 });
    var t = inp.nextToken();
    var id = inp.nextInt();
    w[id] = 0;
    var lft=-1;
    var rgh=1;
    for (it in 2..q) {
        t = inp.nextToken();
        id = inp.nextInt();
        if (t.equals("L")) {
            w[id] = lft;
            --lft;
        } else if (t.equals("R")) {
            w[id] = rgh;
            ++rgh;
        } else {
            out.println(min(w[id] - lft, rgh - w[id]) - 1);
        }
    }
    out.close();
}