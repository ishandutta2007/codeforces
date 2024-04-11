import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=readi()
    repeat(T){
        val (x,y)=readV()
        var rem=y
        var t=1000000000L
        var re=0L
        while(t>0){
            while(rem>=t*x){
                rem-=t*x
                ++re
            }
            t/=10
        }
        re+=rem
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