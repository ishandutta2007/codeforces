import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){println(if(solve()) "Yes" else "No")}
    pw.flush()
}

fun solve(): Boolean {
    val ts = nlint()
    val ss = nlint()
    repeat(2){ti ->
        repeat(2){si ->
            if(ts[ti]!=ss[si]) return@repeat
            if(ts[ti]==ts[1-ti]+ss[1-si]) return true
        }
    }
    return false
}


fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }