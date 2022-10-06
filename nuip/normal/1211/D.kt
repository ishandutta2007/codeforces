import java.io.PrintWriter
import kotlin.math.min
import kotlin.math.max

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var (n,a,b,t) = listOfInt()
    var rs = listOfInt()
    var cnt = MutableList(1000001){0}
    rs.forEach { x -> ++cnt[x] }
    var flip = a<b
    var re=0
    for(i in 1 .. 1000000){
        if(i%t==0) continue
        var vs = mutableListOf<Int>()
        var x = i.toLong()
        while(x<=1000000){
            vs.add(cnt[x.toInt()])
            x*=t.toLong()
        }
        var s=max(a,b)
        var t=min(a,b)
        if(flip) vs = vs.asReversed()
        repeat(vs.size-1){ i ->
            var tmp = min( vs[i]/s, vs[i+1]/t)
            vs[i+1]-=tmp*t
            re+=tmp
        }
    }
    println(re)
    pw.flush()
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }