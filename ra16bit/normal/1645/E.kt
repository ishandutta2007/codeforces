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
    var n = inp.nextInt()
    var m = inp.nextInt()
    var a = ArrayList<Int>()
    for (i in 0..29) if (n.shr(i).and(1) == 1) a.add(i)
    if (m>n || m<a.size) {
        out.println("NO")
        out.close()
        return
    }
    var i=0
    while (a.size<m) {
        if (a[i]==0) {
            i++
            continue
        }
        --a[i]
        a.add(a[i])
    }
    out.println("YES")
    for (i in a) {
        out.print(1 shl i)
        out.print(' ')
    }
    out.close()
}