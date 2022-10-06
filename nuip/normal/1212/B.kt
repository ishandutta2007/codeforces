import java.io.PrintWriter
import kotlin.math.max

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var n = nextInt()
    var s = next()
    var cnt = mutableMapOf<String, Int>()
    repeat(n-1){i ->
        var sub = s.substring(i,i+2)
        cnt.put(sub, cnt.getOrDefault(sub, 0)+1)
    }
    var mx = 0
    var re = ""
    for (p in cnt) {
        if(mx < p.value){
            mx=p.value
            re=p.key
        }
    }
    print(re)
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