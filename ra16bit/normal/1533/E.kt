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
    val n = inp.nextInt();
    var a = Array(n, {i->inp.nextInt()})
    var b = Array(n+1, {i->inp.nextInt()})
    val m = inp.nextInt();
    var c = Array(m, {i->Pair<Int,Int>(inp.nextInt(),i)})
    var r = Array(m, {i->0})
    var d = Array(n, {i->0L})
    a.sort()
    b.sort()
    Arrays.sort(c, Comparator { x: Pair<Int,Int>, y: Pair<Int,Int> ->
        x.first.compareTo(y.first);
    });
    var s = TreeSet<Long>()
    val ADD = 1000100100L
    for (i in 1..n) {
        d[i-1]=b[i].toLong()-a[i-1].toLong() + ADD
        s.add((d[i-1] shl 31) + i-1)
    }
    var j = 0
    for (i in 0..m-1) {
        while (j<n && c[i].first>a[j]) {
            s.remove((d[j] shl 31)+j)
            d[j]=b[j].toLong()-a[j].toLong() + ADD
            s.add((d[j] shl 31) + j)
            ++j
        }
        r[c[i].second] = Math.max(b[j]-c[i].first,((s.last() shr 31) - ADD).toInt())
    }
    for (i in 0..m-1) out.print("${r[i]} ")
    out.close();
}