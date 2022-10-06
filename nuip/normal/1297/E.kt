import java.io.PrintWriter

fun dfs(g:MutableList<MutableList<Int>>, usd: MutableList<Int>, v:Int, p:Int): Boolean{
    for(w in g[v])if(w!=p){
        if(dfs(g,usd,w,v)){
            usd[v]=1
        }
    }
    return usd[v]==1
}

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nextInt()
    for(hoge in 1..T){
        val (n,t)=listOfInt()
        var g= MutableList(n){ mutableListOf<Int>()}
        repeat(n-1){
            var (a,b)=listOfInt()
            --a
            --b
            g[a].add(b)
            g[b].add(a)
        }
        var dd= mutableListOf<Int>()
        for(i in 0..n-1)if(g[i].size == 1) dd.add(i)
        if(dd.size < t) {
            println("No")
            continue
        }
        var usd= MutableList(n){0}
        repeat(t){i -> usd[dd[i]]=1}
        dfs(g,usd,dd[0],-1)
        var re=MutableList<Int>(0){0}
        repeat(n){i -> if(usd[i]==1) re.add(i+1)}
        println("Yes")
        println(re.size)
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