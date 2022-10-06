import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    read()
    val vs=readVi().asReversed()
    val usd= mutableSetOf<Int>()
    val re= mutableListOf<Int>()
    for (v in vs) {
        if(usd.add(v)) re.add(v)
    }
    println(re.size)
    println(re.reversed().joinToString(" "))
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