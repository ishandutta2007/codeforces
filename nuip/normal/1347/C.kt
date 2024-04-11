import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        var n=nint()
        var d=1
        var re= mutableListOf<Int>()
        while(n>0) {
            if(n%10>0) re.add(n%10*d)
            n/=10
            d*=10
        }
        println(re.size)
        println(re.joinToString(" "))
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