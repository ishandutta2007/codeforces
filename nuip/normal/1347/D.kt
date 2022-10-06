import java.io.PrintWriter

val pw = PrintWriter(System.out)
@ExperimentalStdlibApi
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val n=nint()
        val vs=nlint()
        val re= mutableListOf(0,0,0)
        var last=0
        var l=0
        var r=n-1
        while(l<=r){
            var sum=0
            while(l<=r && sum<=last){
                sum+=vs[l++]
            }
            re[1]+=sum
            if(sum>0) ++re[0]
            last=sum
            sum=0
            while(l<=r && sum<=last){
                sum+=vs[r--]
            }
            re[2]+=sum
            if(sum>0) ++re[0]
            last=sum
            sum=0
        }
        println(re.joinToString(" "))
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