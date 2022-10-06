import java.io.PrintWriter
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var T=nint()
    repeat(T){
        val (n,m,t)=nlint()
        val a= min(n/t,m)
        val rem=m-a
        val b=(rem+t-2)/(t-1)
        println(a-b)
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