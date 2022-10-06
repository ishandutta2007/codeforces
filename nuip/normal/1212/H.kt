import java.io.PrintWriter
import java.util.Collections.copy
import java.util.Collections.min
import kotlin.math.min

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var (n,t) = listOfInt()
    var g  = MutableList(n){ mutableListOf<Int>()}
    var ind=mutableMapOf<Pair<Int,Int>,Int>()
    var es = mutableListOf<Pair<Int,Int>>()
    repeat(n-1){
        var (x,y) = listOfInt()
        --x; --y;
        ind[Pair(x,y)]=it
        ind[Pair(y,x)]=it
        es.add(Pair(x,y))
        g[x].add(it)
        g[y].add(it)
    }
    var re=MutableList(n){-1}
    var dp = MutableList(n){ MutableList<MutableList<Int>?>(t+1){null}}
    var sz= MutableList(n){1}
    fun dfs(v:Int, p:Int) {
        dp[v][0]=mutableListOf()
        dp[v][1]= mutableListOf()
        g[v].forEach { ww ->
            if(ww==p) return@forEach
            var w=es[ww].first+es[ww].second-v
            dfs(w,ww)
            sz[v]+=sz[w]
            for(i in min(sz[v],t) downTo 1){
                for(j in 0 until min(sz[w]+1,i)){
                    if(dp[v][i-j]==null || dp[w][j]==null) continue
                    if(j==0 || dp[v][i]==null || dp[v][i-j]!!.size+dp[w][j]!!.size<dp[v][i]!!.size){
                        dp[v][i]=dp[v][i-j]!!.toMutableList()
                        dp[v][i]!!.addAll(dp[w][j]!!)
                    }
                }
            }
        }
        if(dp[v][t]!=null && dp[v][t]!!.size+(if(p<0) 0 else 1)<re.size){
            re=dp[v][t]!!.toMutableList()
            if(p>=0) re.add(p)
        }
        if(p>=0) dp[v][0]!!.add(p)
    }
    dfs(0,-1)
    println(re.size)
    println(re.map{x -> x+1}.joinToString (" "))
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