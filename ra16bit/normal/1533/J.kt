import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.PrintWriter
import java.util.*
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
    var a = Array(500500, { i->ArrayList<Int>() })
    var ux = Array(500500, { i->ArrayList<Boolean>() })
    var uy = Array(500500, { i->ArrayList<Boolean>() })
    for (i in 0..n-1) {
        val x = inp.nextInt();
        val y = inp.nextInt();
        a[y].add(x)
        ux[y].add(false)
        uy[y].add(false)
    }
    var r=n
    for (i in 0..500499) if (!a[i].isEmpty()) {
        a[i].sort()
        if (i==0 || a[i-1].isEmpty()) continue
        var st=ArrayList<Int>()
        var kx=0
        var ky=0
        for (j in 0..a[i-1].size-1) {
            while (kx<a[i].size && a[i][kx]<a[i-1][j]) {
                if (!ux[i][kx]) st.add(kx)
                ++kx
            }
            while (ky<a[i].size && (a[i][ky]<=a[i-1][j] || uy[i][ky])) ++ky
            if (!uy[i-1][j] && !st.isEmpty()) {
                val top=st.size-1
                ux[i][st[top]]=true
                uy[i-1][j]=true
                st.removeAt(top)
                --r
            }
            if (!ux[i-1][j] && ky<a[i].size) {
                ux[i-1][j]=true
                uy[i][ky]=true
                ++ky
                --r
            }
        }
    }
    out.println(r)
    out.close();
}