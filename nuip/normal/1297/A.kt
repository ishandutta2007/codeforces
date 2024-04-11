import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nextInt()
    repeat(T){
        val n = nextInt()
        if(n<1000){
            println(n)
        }else{
            val nk=(n+500)/1000
            if(nk<1000){
                println("${nk}K")
            }else{
                println("${(n+500000)/1000000}M")
            }
        }
    }
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