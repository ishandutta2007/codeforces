import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val (n, m, d) = readV()
    val cs = readV()
    val space = n - cs.sum()
    if (space > (m + 1) * (d - 1)) {
        println("NO")
        return
    }
    println("YES")
    repeat((m + 1).toInt()) { i ->
        repeat(((space + i) / (m + 1)).toInt()) { print("0 ") }
        if (i < m) repeat(cs.get(i).toInt()) { print("${i + 1} ") }
    }
    println()
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