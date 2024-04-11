import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=readi()
    repeat(T){
        val (n,s)=readVl()
        var l=1L
        var r=s+1
        while(r-l>1){
            val m=(l+r)/2
            var sum=0L
            var cur=m
            for(i in 0..n-1){
                if(cur==1L){
                    sum+=n-i
                    break
                }
                sum+=cur
                cur=(cur+1)/2
            }
            if(sum<=s) l=m
            else r=m
        }
        println(l)
    }
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