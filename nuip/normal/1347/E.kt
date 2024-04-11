import java.io.PrintWriter

val ans=mutableListOf(
    mutableListOf(0),
    mutableListOf(0),
    mutableListOf(0),
    mutableListOf(0),
    mutableListOf(1,3,0,2),
    mutableListOf(0,2,4,1,3),
    mutableListOf(4,2,5,1,3,0).reversed(),
    mutableListOf(4,0,2,5,1,3,6).reversed().map { x -> 6-x }
)

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val T=nint()
    repeat(T){
        val n=nint()
        if(n<4){
            println(-1)
        }else{
            val re= mutableListOf<Int>()
            while(re.size<n){
                var sz=re.size
                if(sz+8<=n){
                    for(v in ans[4]) re.add(sz+v+1)
                    continue
                }
                for(v in ans[n-sz]) re.add(sz+v+1)
            }
            println(re.joinToString(" "))
        }
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