import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    var T=nextInt()
    repeat(T){
        val n=nextInt()
        val ints= mutableListOf<Pair<Int,Int>>()
        val cands= mutableListOf<Int>()
        repeat(n){
            val (a,b)=listOfInt()
            ints.add(Pair(a,b))
            cands.add(a)
            cands.add(a-1)
            cands.add(b)
            cands.add(b+1)
        }
        var re=-1
        for(x in cands){
            var cnt=0
            for((a,b) in ints){
                if(a<=x && x<=b) ++cnt
            }
            if(cnt==1) re=x
        }
        println(re)
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