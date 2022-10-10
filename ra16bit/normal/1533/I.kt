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

class Kuhn {
    var g = Array(111*111*2, { i->ArrayList<Int>() })
    var was = Array(111*111*2, { i->false })
    var u = Array(111*111*2, { i->0 })
    var b = Array(222, { i->-1 })
    var it = 0

    fun dfs(x: Int): Boolean {
        if (u[x]==it) return false;
        u[x]=it
        for (nxt in g[x]) if (b[nxt]==-1 || dfs(b[nxt])) {
            b[nxt]=x
            was[x]=true
            return true
        }
        return false;
    }

    fun run(x: Int): Boolean {
        if (was[x]) return false
        ++it
        return dfs(x)
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val na = inp.nextInt();
    val nb = inp.nextInt();
    val m = inp.nextInt();
    var a = Array(na, { i-> inp.nextInt() })
    var k = Array(na, { i-> i })
    Arrays.sort(k, Comparator { x: Int, y: Int ->
        a[x].compareTo(a[y]);
    });

    var v = Array(na, { i->ArrayList<Int>() })
    var kuhn = Kuhn()
    for (i in 0..m-1) {
        val x = inp.nextInt()-1;
        val y = inp.nextInt()-1;
        v[x].add(m+i)
        kuhn.g[i].add(x)
        kuhn.g[i].add(na+y)
        if (kuhn.b[x]==-1) {
            kuhn.b[x]=i;
            kuhn.was[i]=true;
        } else if (kuhn.b[na+y]==-1) {
            kuhn.b[na+y]=i;
            kuhn.was[i]=true;
        }
        kuhn.g[m+i].add(x)
        kuhn.g[m+i].add(na+y)
    }
    for (i in 0..m-1) kuhn.run(i)
    var res = 0
    for (i in 0..na-1) for (st in v[k[i]]) if (kuhn.run(st)) res+=a[k[i]]
    out.println(res)
    out.close();
}