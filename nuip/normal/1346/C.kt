import java.io.PrintWriter
import java.lang.Integer.min
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val (n,ub,x,y)=nllong()
        val books=nllong().sorted().asReversed()
        var sum=books.sum()
        val ubs=ub*n
        var re=x*n
        var cur=0L
        books.forEachIndexed { i, v ->
            if(sum<=ubs) re=min(re,cur+y)
            if(v<=ub) re=min(re,cur)
            sum-=v
            cur+=x
        }
        println(re)
    }
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }