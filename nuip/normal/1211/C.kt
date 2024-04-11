import java.io.PrintWriter
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var (n,t)=listOfInt()
    var ls = mutableListOf<Int>()
    var rs = mutableListOf<Int>()
    var cs = mutableListOf<Int>()
    repeat(n){
        var (l, r, c) = listOfInt()
        ls.add(l)
        rs.add(r)
        cs.add(c)
    }
    var re = 0L
    var rem = t
    repeat(n){ i ->
        re += ls[i].toLong() * cs[i].toLong()
        rem -= ls[i]
        if(rem<0){
            println("-1")
            return
        }
    }
    var inds = MutableList(n){i -> i}.sortedBy { i -> cs[i] }
    repeat(n) { ii->
        var i = inds[ii]
        if(ii>0) assert(cs[inds[ii-1]]<cs[inds[ii]])
        var tmp = min(rem, rs[i]-ls[i])
        if(tmp<0) tmp = 0
        rem -= tmp
        re += tmp.toLong() * cs[i].toLong()
    }
    if(rem==0) {
        println(re)
    }else {
        println("-1")
    }
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