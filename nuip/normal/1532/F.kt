import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    val n=readInt()
    val ss=readVString(2*(n-1))
    val xs= MutableList(n){""}
    val ys= MutableList(n){""}
    val xis= MutableList(n){-1}
    val yis= MutableList(n){-1}
    for(i in 0..ss.size-1) {
        val s=ss[i]
        if(xs[s.length].length>0) {
            ys[s.length] = s
            yis[s.length] = i
        } else {
            xs[s.length] = s
            xis[s.length] = i
        }
    }
    val cands= mutableListOf<String>()
    for(xss in arrayOf(xs, ys)) {
        for(yss in arrayOf(xs, ys)) {
            if(xss[1]===yss[n-1]) continue
            cands.add(xss[1]+yss[n-1])
            cands.add(yss[n-1]+xss[1])
        }
    }
    for(cand in cands) {
        var ok=true
        for(i in 1..n-1){
            if(cand.startsWith(xs[i]) && cand.endsWith(ys[i]) ||
                cand.startsWith(ys[i]) && cand.endsWith(xs[i])) ;
            else ok=false
        }
        if(!ok) continue
        val re= MutableList(2*(n-1)){'a'}
        for(i in 1..n-1){
            if(cand.startsWith(xs[i]) && cand.endsWith(ys[i])){
                re[xis[i]]='P'
                re[yis[i]]='S'
            }else {
                re[xis[i]]='S'
                re[yis[i]]='P'
            }
        }
        println(re.joinToString(""))
        return
    }
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