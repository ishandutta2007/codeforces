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

class Field {
    var u = Array(14, { i->Array(14,{j->false})})
    var dx = Array(4, {i->0})
    var dy = Array(4, {i->0})
    var cnt = 0
    var r = Array(222, { i->Array(222,{j->0})})
    var px = 0
    var py = 0
    var mx = 0
    var my = 0

    constructor() {
        dx[0]=-1; dx[2]=1;
        dy[1]=-1; dy[3]=1;
    }

    fun dfs(x: Int, y: Int, n: Int, m: Int, a:Array<Array<Int>>) {
        r[px][py]=a[x][y]
        mx=Math.max(mx,px)
        my=Math.max(my,py)
        u[x][y]=true;
        ++cnt
        for (d in 0..3) {
            var nx = x + dx[d];
            var ny = y + dy[d];
            if (nx>=0 && nx<n && ny>=0 && ny<m && a[nx][ny]!=0 && u[nx][ny]==false) {
                py += 1
                dfs(nx,ny,n,m,a);
                px += 1
                r[px][py]=a[x][y]
            }
        }
    }

    fun normalize() {
        for (i in 1..mx) for (j in 0..my-1) if (r[i][j]==0) r[i][j]=r[i-1][j+1]
        for (i in mx-1 downTo 0) for (j in 1..my) if (r[i][j]==0) r[i][j]=r[i+1][j-1]
    }

}

fun main(args: Array<String>) {
    val inp = IOStream()
    val out = PrintWriter(System.out)
    val tt = inp.nextInt();
    for (t in 1..tt) {
        val n = inp.nextInt();
        val m = inp.nextInt();
        var a = Array(n, { i -> Array(m, { j -> inp.nextInt() }) })
        var tot = 0
        for (i in 0..n - 1) for (j in 0..m - 1) if (a[i][j] != 0) ++tot
        var was = false
        var f = Field()
        for (i in 0..n - 1) if (!was) for (j in 0..m - 1) if (a[i][j] != 0) {
            f.dfs(i, j, n, m, a)
            was = true;
            break;
        }
        if (f.cnt == tot) {
            f.normalize()
            out.println("${f.mx+1} ${f.my+1}")
            for (i in 0..f.mx) {
                for (j in 0..f.my) out.print("${f.r[i][j]} ")
                out.println()
            }
        } else out.println(-1)
    }
    out.close();
}