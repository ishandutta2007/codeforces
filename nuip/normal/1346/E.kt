import java.io.PrintWriter
import java.lang.Integer.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val (n,m,init)=nlint()
    val ps=List(m){
        val (x,y)=nlint()
        x-1 to y-1
    }
    val INF=1000111000

    val dp=MutableList(n){INF}
    dp[init-1]=0

    for(p in ps){
        val f=dp[p.first]
        val s=dp[p.second]
        dp[p.first]=min(f+1,s)
        dp[p.second]=min(f,s+1)
    }
    println(dp.map { x -> if(x==INF) -1 else x }.joinToString(" "))
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