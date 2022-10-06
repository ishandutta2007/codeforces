import java.io.PrintWriter
import java.util.*
import kotlin.math.min

val pw = PrintWriter(System.out)
val memo = MutableList(212345){-1}
fun ok(ps: List<Int>, m : Int): Boolean{
    var que:Queue<Int> = LinkedList<Int>()
    ps.forEach { x ->
        if(x>m) return@forEach
        if(memo[x]!=m){
            memo[x]=m
            que.add(x)
        }else{
            if(que.isEmpty()) return false
            var y = que.poll()
            if(x!=y) return false
        }
    }
    return true
}

fun main(args: Array<String>) {
    var n = nextInt()
    var ps = listOfInt()
    var cnt = MutableList(212345){0}
    ps.forEach { x -> ++cnt[x] }
    var r = 1
    while(cnt[r] == 2) ++r
    var que:Queue<Int> = LinkedList<Int>()
    ps.forEach { x ->
        if(x>=r) return@forEach
        if(memo[x]!=1){
            memo[x]=1
            que.add(x)
        }else{
            while(que.isNotEmpty() && que.peek()>x){
                r = min(r, que.peek())
                que.poll()
            }
            if(que.peek()==x){
                que.poll()
            }else{
                r=min(r,x)
            }
        }
    }
   println(ps.map { p ->
        if(p < r){
            if(memo[p]!=-2){
                memo[p]=-2
                'R'
            }else{
                'G'
            }
        }else{
            'B'
        }
    }.joinToString(""))
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