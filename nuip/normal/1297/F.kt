import java.io.PrintWriter
import java.util.*
import kotlin.math.max


val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nextInt()
    repeat(T){
        val (n,m)=listOfInt()
        var iis=mutableListOf<Pair<Pair<Int,Int>,Int>>()
        repeat(n){
            val (a,b)= listOfInt()
            iis.add(Pair(Pair(a,b),it))
        }
        iis.sortBy { it.first.first }
        var ints= MutableList(n){i:Int -> iis[i].first}
        var re=MutableList(n){0}
        var l=0
        var r=1000000000
        check(ints,1,re,m)
        if(check(ints,0,re,m)){
            r=0
        }
        while(r-l>1){
            var med=(l+r)/2
            if(check(ints,med,re,m)){
                r = med
            }else {
                l = med
            }

        }
        println(r)
        check(ints,r,re,m)
        var ans=MutableList(n){0}
        repeat(n){i -> ans[iis[i].second]=re[i]}
        println(ans.joinToString(" "))
    }
    pw.flush()
}

fun check(ints: MutableList<Pair<Int, Int>>, m: Int, re: MutableList<Int>, ub:Int): Boolean {
    var i=0
    var pq=PriorityQueue<Pair<Int,Int>>{a,b -> a.first-b.first}
    var t=0
    while(true){
        if(pq.isEmpty()){
            if(i==ints.size) break
            t= max(t,ints[i].first)
        }
        while(i<ints.size && ints[i].first==t){
            pq.add(Pair(ints[i].second+m,i))
            ++i
        }
        for(i in 1..ub){
            if(pq.isEmpty()) break
            val (dl,ind)=pq.poll()!!
            if(dl<t) return false
            re[ind]=t
        }
        ++t
    }
    return true
}

fun next() = readLine()!!
fun nextInt() = next().toInt()
fun nextLong() = next().toLong()
fun nextDouble() = next().toDouble()
fun listOfString() = next().split(" ")
fun listOfInt() = listOfString().map { it.toInt() }
fun listOfLong() = listOfString().map { it.toLong() }
fun listOfDouble() = listOfString().map { it.toDouble() }