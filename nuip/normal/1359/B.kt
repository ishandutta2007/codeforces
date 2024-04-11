import java.io.PrintWriter
import java.lang.Integer.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        var (n,m,a,b)=nlint()
        b=min(b,a+a)
        val mp= MutableList<String>(n){next()}
        var re=0L
        for(ss in mp){
            val s=ss+"*"
            var cnt=0
            for (c in s) {
                if(c=='*'){
                    re+=cnt/2*b
                    re+=cnt%2*a
                    cnt=0
                }else{
                    ++cnt
                }
            }
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