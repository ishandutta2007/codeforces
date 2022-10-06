import java.io.PrintWriter
import java.lang.Integer.max

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val n=nint()
        println(max(0,(n-1)/2))
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