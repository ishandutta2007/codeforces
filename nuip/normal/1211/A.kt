import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextInt()
    var vs = listOfInt()
    var re=0L
    var i = 1
    for(v in vs){
        var li = -1
        var ri = -1
        var j = 1
        for(w in vs){
            if(w<v) li=j
            if(w>v) ri=j
            ++j
        }
        if(li>=0 && ri>=0){
            println("$li $i $ri")
            pw.flush()
            return
        }
        ++i
    }
    println("-1 -1 -1")
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