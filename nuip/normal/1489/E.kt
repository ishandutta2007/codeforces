import java.io.PrintWriter
import java.lang.Integer.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val q=readi()
    val vs= IntArray(212345)
    var l=0
    var r=1
    repeat(q){
        val (c,vv)=readVs()
        val v=vv.toInt()
        if(c=="L") {
           vs[v]=l--
        }else if(c=="R") {
           vs[v]=r++
        }else{
            println(min(vs[v] - l, r - vs[v])-1)
        }
    }
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(' ')
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