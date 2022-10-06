import java.io.PrintWriter
import kotlin.math.abs

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val (h,c,t)=nlint()
        println(solve(h,c,t))
    }
    pw.flush()
}

fun solve(h: Int, c: Int, t: Int): Long {
    if(h==t) return 1
    if(t*2<=h+c) return 2
    var pw=1L shl 40
    var re=1L
    while(pw>1){
        if((re+pw+1)/2*h+(re+pw)/2*c>=t*(re+pw)) re+=pw
        pw/=2
    }
    var a= abs((re+1)/2*h+re/2*c-t*re)*(re+2)
    var b= abs((re+2+1)/2*h+(re+2)/2*c-t*(re+2))*re
    return if(a<=b) re else re+2
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }