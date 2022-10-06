import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextLong()
    var vs = listOfLong()
    var ind = 0
    var mx = -1L
    for(i in n-1 downTo  0){
        if(mx<vs[i.toInt()]){
            ind= i.toInt()
            mx=vs[i.toInt()]
        }
    }
    println(mx*n-(n-1-ind))
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