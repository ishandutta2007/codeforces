import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val n=readi()
    val re=IntArray(n)
    val st=PriorityQueue(compareByDescending<Pair<Int,Int>>{it.first}.thenBy{it.second})
    val cur=IntArray(n+1){if(it>0) n/it-1 else 0}
    for(i in 1..n)if(cur[i]>0) st.add(Pair(cur[i],i))
    for(i in 1..n-1){
        while(st.isNotEmpty() && st.peek().first!=cur[st.peek().second]) st.poll()
        if(st.isEmpty()){
            re[i]=re[i-1]
            continue
        }
        val (ad,v)=st.poll()
//        println("$v,${cur[v]}")
//        st.remove(Pair(ad,v))
        re[i]=re[i-1]+ad
        var j=v+v
        while(j<=n){
//            st.remove(Pair(cur[j],j))
            cur[j]--
            st.add(Pair(cur[j],j))
            j+=v
        }
    }
    println(re.reversed().joinToString(" "))
    pw.flush()
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }
fun reads() = next()
fun readi() = nint()
fun readl() = nlong()
fun readd() = ndouble()
fun readVs() = nlstring()
fun readVi() = nlint()
fun readVl() = nllong()
fun readVd() = nldouble()
fun read() = readl()
fun readV() = readVl()