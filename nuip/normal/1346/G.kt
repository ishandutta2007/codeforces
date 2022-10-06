import java.io.PrintWriter

val pw = PrintWriter(System.out)
fun main(args: Array<String>) {
//    repeat(100){i ->
//        repeat(100) { j ->
//            var g=gcd(i,j)
//            var h=0
//            repeat(101) {k -> if(k>0 && i%k==0 && j%k==0) h=k}
//            if(i==0 && j==0) h=0
//            if(g!=h){
//                println("$i $j $g $h")
//                return
//            }
//        }
//    }
    val (m,n)=nlint()
    val periods=nlint()
    val xs=nlint()

    val ds=List(n-1){xs[it+1]-xs[it]}
    val st=RMQSparseTable(ds.toIntArray())

    val inv=MutableList(1123456){-1}
    repeat(xs.size){
        inv[xs[it]]=it
    }

    val divp=MutableList(1123456){0}
    for(p in periods){
        for(i in 0..1123455 step p) divp[i]=p
    }

    for(p in periods){
        var alast=0
        var blast=-1
        var binit=0
        var g=0
        val hoge= mutableListOf<Int>(xs[0])
        for (i in xs[0]+p..1123455 step p){
            if(inv[i]<0) continue
            hoge.add(i)
            if(alast+1==inv[i]) {
            }else {
                if(blast>=0){
                    g=gcd(g, xs[alast+1] - xs[blast])
                }else{
                    binit=alast+1
                }
                g = gcd(g, st.get(alast + 1, inv[i]))
                blast=inv[i]-1
            }
            alast=inv[i]
        }
        if(alast+1==n){
        }else{
            if(blast>=0){
                g=gcd(g, xs[alast+1] - xs[blast])
            }else{
                binit=alast+1
            }
            g = gcd(g, st.get(alast + 1, n))
        }
        if(divp[g]>0){
//            val st=mutableSetOf<Int>()
//            for(i in xs[0]..1123456 step periods[0]) st.add(i)
//            for(i in xs[binit]..1123456 step divp[g]) st.add(i)
//            for(i in hoge)if(!st.contains(i)) println(next())
//            var ok=1
//            for(x in xs)if(!st.contains(x)) ok=0
//
//            if(ok==0) continue

            println("YES")
            println("${xs[0]} ${p}")
            println("${xs[binit]} ${divp[g]}")

            pw.flush()
            return
        }
    }
    println("NO")
    pw.flush()
}

fun gcd(x_: Int, y_:Int): Int {
    var x=x_
    var y=y_
    while(true){
        if(x<y){
            x=y.also { y=x }
        }
        if(y==0) return x
        x%=y
    }
    return x
}

class RMQSparseTable(var a: IntArray) {
    var logTable: IntArray
    var rmq: Array<IntArray>

    fun get(l:Int, r:Int): Int {
        if(r-l<=1) return 0
        return minPos(l,r-2)
    }

    fun minPos(i: Int, j: Int): Int {
        val k = logTable[j - i]
        val x = rmq[k][i]
        val y = rmq[k][j - (1 shl k) + 1]
        return gcd(x,y)
    }

    init {
        val n = a.size
        logTable = IntArray(n + 1)
        for (i in 2..n) logTable[i] = logTable[i shr 1] + 1
        rmq = Array(logTable[n] + 1) { IntArray(n) }
        for (i in 0 until n) rmq[0][i] = a[i]
        var k = 1
        while (1 shl k < n) {
            var i = 0
            while (i + (1 shl k) <= n) {
                val x = rmq[k - 1][i]
                val y = rmq[k - 1][i + (1 shl k - 1)]
                rmq[k][i] = gcd(x,y)
                i++
            }
            ++k
        }
    }
}

fun next() = readLine()!!
fun nint() = next().toInt()
fun nlong() = next().toLong()
fun ndouble() = next().toDouble()
fun nlstring() = next().split(" ")
fun nlint() = nlstring().map { it.toInt() }
fun nllong() = nlstring().map { it.toLong() }
fun nldouble() = nlstring().map { it.toDouble() }