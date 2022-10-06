import java.io.PrintWriter

val MOD=998244353L

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
    val (n,t)=nlint()
    val fact= MutableList<Long>(512345){1}
    for(i in 1..512344) fact[i]=fact[i-1]*i%MOD
    val finv= MutableList<Long>(512345){1}
    finv[finv.lastIndex]=modpow(fact[fact.lastIndex],MOD-2)
    for(i in 512344 downTo 1) finv[i-1]=finv[i]*i%MOD
    var re=0L
    var r=t-1
    for(i in 1..n){
        var m=n/i-i/i
        if(m<r) continue
        re+=fact[m]*finv[r]%MOD*finv[m-r]%MOD
    }
    println(re%MOD)
    pw.flush()
}

fun modpow(r_:Long, n_: Long): Long {
    var n=n_
    var r=r_
    var re=1L
    while(n>0){
        if(n%2==1L){
            re*=r
            re%=MOD
        }
        n/=2
        r*=r
        r%=MOD
    }
    return re
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }