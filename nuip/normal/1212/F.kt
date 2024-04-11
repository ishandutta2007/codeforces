import java.io.PrintWriter
import java.lang.Math.abs
import java.lang.Math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var INF = 1000000000000000L
    var n = nextLong()
    var vs = mutableListOf(1L)
    repeat(16){
        vs.add(vs.get(it)*10+1)
    }
    var dp = mapOf(Pair(n,0L))
    var re = n;
    for(i in 16 downTo 0){
//        dp.forEach { t, u ->  print("${t} ${u}\n")}
//        println("")
        var nxt = mutableMapOf<Long,Long>()
        var upd = { key:Long, value:Long ->
            var cur = nxt.getOrDefault(key, INF)
            nxt.put(key, min(cur, value))
        }
        dp.forEach { n_, c ->
            var n = abs(n_)
            if(n==0L){
                re= min(re, c)
                return@forEach
            }
            var t=n/vs[i]
            upd(n-t*vs[i], c+(i+1)*t)
            upd((t+1)*vs[i]-n, c+(i+1)*(t+1))
        }
        dp=nxt
    }
    print(min(re, dp.getOrDefault(0, INF)))
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