import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    read()
    val s=reads()
    var cnt=0
    var re=0
    for (c in s) {
        if(c=='x') ++cnt
        else cnt=0
        if(cnt==3){
            ++re
            --cnt
        }
    }
    println(re)
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