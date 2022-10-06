import java.io.PrintWriter
import java.lang.Integer.min
import java.lang.Integer.max

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=readi()
    repeat(T){
        val (n,x,y)=readVi()
        val l=min(x,y)-1
        val r= max(x,y) -1
        var re=10000000
        for(i in l+1..r){
            val x=i-1+min(l,i-l-1)
            val y=n-1-i+min(r-i,n-1-r)
            //println("$i $x $y")
            re=min(re,max(x,y))
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