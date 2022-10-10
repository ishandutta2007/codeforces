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
        val cnt = inp.nextInt()
        var lftv=0;
        var rghv=200200;
        for (ii in 1..cnt) {
            val a = inp.nextToken()
            val b = inp.nextToken()
            val c = inp.nextInt()
            val n = a!!.length
            val m = b!!.length
            val len = Math.min(n,m)
            for (i in 1..len+1) if (i==len+1 || a!![n-i]!=b!![m-i]) {
                if (c==1) {
                    rghv=Math.min(rghv,i-1);
                } else {
                    lftv=Math.max(lftv,i);
                }
                break;
            }
        }
        out.println(Math.max(0,rghv-lftv+1));
        for (i in lftv..rghv) out.print("$i ");
        out.println();
    }
    out.close();
}