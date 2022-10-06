import java.io.PrintWriter
import java.lang.Integer.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val (n,k1,k2)=nlint()
        val s=next()
        var last=0
        var re=0L
        for(i in 0..n-1){
            var t=min(k1,k2-last)
            if(s[i]=='0') t=0
            last=t
            re+=t
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