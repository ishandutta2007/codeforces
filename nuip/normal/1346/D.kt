import java.io.PrintWriter
import java.lang.Integer.max
import java.lang.Integer.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        solve()
    }
    pw.flush()
}

fun solve() {
    val (n,m)=nlint()
    val g= MutableList(n){mutableListOf<Pair<Int,Int>>()}
    repeat(m){
        val (a,b,c)=nlint()
        g[a-1].add(Pair(b-1,c))
        g[b-1].add(Pair(a-1,c))
    }
    val a= MutableList(n){0}
    repeat(n){v ->
        for (pair in g[v]) {
            a[v]=max(a[v], pair.second)
        }
    }
    repeat(n){v ->
        for (pair in g[v]) {
            if(min(a[v],a[pair.first])!=pair.second){
                println("NO")
                return
            }
        }
    }
    println("YES")
    println(a.joinToString(" "))
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }