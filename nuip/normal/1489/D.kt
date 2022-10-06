import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val n=readi()
    val ss=List(n){reads()}.sortedBy { s -> s.length }
    var ok=true
    for(i in 1..n-1) if(!ss[i].contains(ss[i-1])){
        ok=false; break;
    }
    if(ok) {
        println("YES")
        println(ss.joinToString("\n"))
    }else {
        println("NO")
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