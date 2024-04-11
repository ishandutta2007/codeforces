import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var vs = listOfLong()
    var sum = vs.sum() / 3
    var re = listOf<Long>().toMutableList()
    vs.forEach { v -> if(v!=sum) re.add(sum-v) }
    println(re.joinToString(" "))
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