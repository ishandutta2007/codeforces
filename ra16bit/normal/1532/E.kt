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
    var a = Array(n, { i-> inp.nextInt()});
    val MX = 1000010;
    var cnt = Array(MX, { i-> 0});
    var s = 0L;
    for (i in 0..n-1) {
        cnt[a[i]]+=1
        s+=a[i];
    };
    var res = ArrayList<Int>();
    for (i in 0..n-1) {
        s -= a[i];
        --cnt[a[i]];
        if (s % 2 == 0L) {
            var idx = s / 2;
            if (idx < MX && cnt[idx.toInt()] > 0) res.add(i+1);
        }
        ++cnt[a[i]];
        s += a[i];
    }
    out.println(res.size);
    for (x in res) out.print("${x} ");
    out.println();
    out.close();
}