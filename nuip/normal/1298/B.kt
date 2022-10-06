import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextInt()
    var vs = listOfInt()
    var usd = MutableList<Int>(11234){0}
    var re = mutableListOf<Int>()
    for (v in vs.reversed()) {
        if(usd[v]==0){
            usd[v]=1
            re.add(v)
        }
    }
    println(re.size)
    println(re.reversed().joinToString(" "))
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