import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    val n=readInt()
    val m=readInt()
    val ps=List(n){read(0) to read(0)}
    val dp=List(n+1){IntArray(m+1){-1} }
    dp[0][0]=0;
    for(i in 0..n-1){
        for(j in 0..m)if(dp[i][j]>=0) dp[i+1][j]=j
        if(ps[i].second==2){
            val t=ps[i].first
            for(j in 0..m-t)if(dp[i][j]>=0) dp[i+1][j+t]=j
        }
    }
    val sum1=ps.sumOf { (a,b) -> if(b==1) a else 0 }
    val sum2=ps.sumOf { (a,b) -> if(b==2) a else 0 }
    val rej=run{
        for(j in 0..m)if(sum1+j*2-1<=m && sum1+(sum2-j)*2<=m && dp[n][j]>=0) return@run j
        -1
    }
    if(rej<0){
        println(-1)
        return
    }
    val re0= MutableList(0){0}
    val re1= MutableList(0){0}
    val re2= MutableList(0){0}
    run{
        var j=rej
        for(i in n downTo 1) {
            if(dp[i][j]!=j){
                re0.add(i-1)
            }else if(ps[i-1].second==2){
                re1.add(i-1)
            }else{
                re2.add(i-1)
            }
            j=dp[i][j]
        }
    }
    val re= MutableList(n){0}
    var cnt2=0
    for(i in re2){
        re[i]=cnt2
        cnt2+=ps[i].first
    }
    var cnt0=cnt2
    var cnt1=cnt2+1
    for(i in re0){
        re[i]=cnt0
        cnt0+=ps[i].first*2
    }
    for(i in re1){
        re[i]=cnt1
        cnt1+=ps[i].first*2
    }
    println(re.map { it + 1 }.joinToString(" "))
}

@JvmField
val INPUT = System.`in`

@JvmField
val OUTPUT = System.out

@JvmField
val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!

@JvmField
var _tokenizer: StringTokenizer = StringTokenizer("")
fun _read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}

fun readInt() = _read().toInt()
fun readDouble() = _read().toDouble()
fun readLong() = _read().toLong()
fun readString() = _read()
fun readVString(n: Int) = List(n) { _read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readVInt(n: Int) = List(n) { _read().toInt() }
fun readAInt(n: Int) = IntArray(n) { _read().toInt() }
fun readVDouble(n: Int) = List(n) { _read().toDouble() }
fun readADouble(n: Int) = DoubleArray(n) { _read().toDouble() }
fun readVLong(n: Int) = List(n) { _read().toLong() }
fun readALong(n: Int) = LongArray(n) { _read().toLong() }
fun read(d: Int) = readInt() - d
fun read(d: Long) = readInt() - d
fun readV(n: Int, d: Int) = readVInt(n).map { x -> x - d }
fun readV(n: Int, d: Long) = readVLong(n).map { x -> x - d }
fun readA(n: Int, d: Int) = readAInt(n).map { x -> x - d }
fun readA(n: Int, d: Long) = readALong(n).map { x -> x - d }

@JvmField
val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) {
    _writer.apply(block).flush()
}

// old
//fun next() = readLine()!!
//fun nint() = next().toInt()
//fun nlong() = next().toLong()
//fun ndouble() = next().toDouble()
//fun nlstring() = next().split(" ")
//fun nlint() = nlstring().map { it.toInt() }
//fun nllong() = nlstring().map { it.toLong() }
//fun nldouble() = nlstring().map { it.toDouble() }
//fun reads() = next()
//fun readi() = nint()
//fun readl() = nlong()
//fun readd() = ndouble()
//fun readVs() = nlstring()
//fun readVi() = nlint()
//fun readVl() = nllong()
//fun readVd() = nldouble()
//
//fun read() = readl()
//fun readV() = readVl()