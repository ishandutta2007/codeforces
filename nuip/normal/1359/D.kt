import java.io.PrintWriter
import java.lang.Long.max
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val n=nint()
    val vs=nlint()
    var re=0L
    for(x in 1..30){
        var sum=0L
        var mn=0L
        for(v in vs){
            if(v>x){
                sum=0
                mn=0
                continue
            }
            sum+=v
            mn=min(mn,sum)
            re=max(re,sum-mn-x)
        }
    }
    println(re)
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