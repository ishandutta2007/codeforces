import java.io.PrintWriter
import java.lang.Long.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=readi()
    repeat(T){
        val (n,a,b)=readVl()
        println(n / 2 * min(a * 2, b) + n % 2 * a)
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
fun reads() = next()
fun readi() = nint()
fun readl() = nlong()
fun readd() = ndouble()
fun readVs() = nlstring()
fun readVi() = nlint()
fun readVl() = nllong()
fun readVd() = nldouble()
fun read() = readl()
fun readV() = readVl()