import java.io.PrintWriter
import java.lang.Math.abs
import java.lang.Math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nextInt()
    repeat(T){
        val n=nextInt()
        val vs=listOfInt()
        var re= MutableList(n){0}
        var mn=112345
        var sum=0
        for(i in 0..n-1){
            if(vs[i]>0){
                re[i]=1
                sum+=vs[i]
            }
            if(vs[i]!=0) mn=min(mn,abs(vs[i]))
        }
        for(i in 0..n-1)if(abs(vs[i])==mn){
            re[i]=1-re[i]
            break
        }
        sum-=mn
        println(sum)
        println(re.joinToString(""))
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