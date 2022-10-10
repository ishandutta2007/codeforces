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
    out.print("?");
    for (i in 0..99) out.print(" $i");
    out.println()
    out.flush();
    var x = inp.nextInt()
    out.print("?");
    for (i in 1..100) out.print(" ${i.shl(7)}");
    out.println()
    out.flush();
    var y = inp.nextInt()
    out.print("! ");
    out.println(y.and(127) + x.and(1.shr(14) - 128));
    out.flush();
    out.close();
}