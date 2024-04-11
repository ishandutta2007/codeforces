import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextInt()
    var vs = listOfLong().sortedBy { xx ->
        var x=xx
        var a = 0
        while(x%3== 0L){
            x/=3
            --a
        }
        var b = 0
        while(x%2==0L){
            x/=2;
            ++b
        }
        a*100+b
    }
    print(vs.joinToString(" "))
    pw.flush()
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }