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
    var a = Array(n, { i -> inp.nextInt() })
    var x = kotlin.collections.ArrayList<Int>()
    var y = kotlin.collections.ArrayList<Int>()
    var res = Array(n, { i -> 0 })
    var ok = true
    var i = 1
    while (i<n && ok) {
        if (a[i]==a[i-1]) {
            if (x.isEmpty() || x.last() < a[i]) x.add(a[i]); else ok=false;
            if (y.isEmpty() || y.last() > a[i]) {
                y.add(a[i])
                res[i]=1;
            }; else ok=false;
            i+=2;
        } else if (a[i-1]<a[i]) {
            if (x.isEmpty() || x.last() < a[i-1]) x.add(a[i-1]);
              else if (y.isEmpty() || y.last() > a[i-1]) {
                  y.add(a[i-1])
                  res[i-1]=1;
            }; else ok=false;
            i++
        } else {
            if (y.isEmpty() || y.last() > a[i-1]) {
                y.add(a[i-1])
                res[i-1]=1;
            }; else if (x.isEmpty() || x.last() < a[i-1]) x.add(a[i-1]); else ok=false;
            i++;
        }
    }
    if (i==n) {
        if (x.isEmpty() || x.last() < a[i-1]) x.add(a[i-1]);
          else if (y.isEmpty() || y.last() > a[i-1]) {
              y.add(a[i-1])
              res[i-1]=1;
        }; else ok=false;
    }
    if (ok) {
        out.println("YES")
        for (i in 0..n-1) out.print("${res[i]} ")
    } else out.println("NO")
    out.close()
}