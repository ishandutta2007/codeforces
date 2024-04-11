import java.io.PrintWriter
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nextInt()
    repeat(T){
        val (n,t)=listOfInt()
        val a=listOfLong()
        val b=a.sorted().reversed()
        var l= 0L
        var r=3000000000
        while(r-l>1){
            var m=(l+r)/2
            var sum=0L
            for(i in 0..n-1){
                val tmp=m-i-b[i]
                if(tmp<0){
                    sum=-1
                    break
                }
                sum+=tmp
            }
            if(sum>=t) r=m else l=m
        }
        var rem=t.toLong()
        var re=MutableList<Long>(n){0}
        var ps=MutableList<Pair<Long,Int>>(n){i -> Pair(a[i],i)}.sortedBy({it.first}).reversed()
        var ub=r
        for((a,i) in ps){
            var t= min(rem,ub-a)
            rem-=t
            re[i]=t
            --ub
        }
        println(re.joinToString (" "))
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