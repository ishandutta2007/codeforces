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
    val n = inp.nextInt();
    val k = inp.nextInt();
    val x = inp.nextInt();
    val a = Array(n, { i -> inp.nextInt() })
    var le = 0L
    var ri = x*100000L
    while (le<ri) {
        var h=(le+ri)/2
        var cnt = 0
        var sum = 0L
        var i = 0
        val comparator = compareBy<Int> { -it }
        var q = PriorityQueue<Int>(comparator);
        for (i in 0..n-1) {
            sum += a[i]
            q.add(a[i])
            if (sum > h) {
                var v=q.remove()
                sum -= v
                ++cnt
                if (cnt > k) break;
            }
            if (q.size == x) {
                while (!q.isEmpty()) q.remove();
                sum = 0L
            }
        }
        if (cnt<=k) ri=h; else le=h+1;
    }
    out.println(ri)
    out.close();
}