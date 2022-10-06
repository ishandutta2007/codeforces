import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val n = nextInt()
    val s = next()
    var cnt = 0
    var re =0
    for(c in s){
        if(c=='x'){
            ++cnt
            if(cnt==3){
                --cnt
                ++re
            }
        }else{
            cnt=0
        }
    }
    println(re)
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