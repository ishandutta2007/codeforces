import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    repeat(readInt()) {
        val n = readInt()
        val s = readString()
        val t = readString()
        val cur = IntArray(n) { 0 }
        val dif = IntArray(n) { 0 }
        for (i in 0..t.length - 1) if (t[i] == '1') {
            cur[i] = 1
            dif[i + 2] = 1
            cur[i + 3] = -1
        }
        val fn = { lb:Int, ub:Int ->
            var pos=true
            var neg=true
            for(i in lb..ub-1)if(cur[i]!=0){
                if(cur[i]==1 && i%2==lb%2){
                    neg=false
                }else{
                    pos=false
                }
            }
            var pcos=n
            var ncos=n
            if(pos){
                pcos=0
                for(i in lb..ub-1) {
                    if(i%2==lb%2){
                        if(s[i]!='(') ++pcos
                    }else{
                        if(s[i]!=')') ++pcos
                    }
                }
            }
            if(neg){
                ncos=0
                for(i in lb..ub-1) {
                    if (i % 2 == lb % 2) {
                        if (s[i] != ')') ++ncos
                    } else {
                        if (s[i] != '(') ++ncos
                    }
                }
            }
            if(pcos<ncos){
                for(i in lb..ub-1) cur[i]=if(i%2==lb%2) 1 else -1
            }else{
                for(i in lb..ub-1) cur[i]=if(i%2==lb%2) -1 else 1
            }
        }
        var lb=0
        for (i in 0..n-1){
            if(dif[i]==0){
                fn(lb,i)
                lb=i
            }
        }
        fn(lb,n)
        var ok=true
        for(i in 0..n-4)if(t[i]=='1'){
            if(cur[i]!=1) ok=false;
            if(cur[i+1]==cur[i+2]) ok=false;
            if(cur[i+3]!=-1) ok=false;
        }
        if(ok){
            println((0..n-1).sumOf {
                if(cur[it]>0){
                    if(s[it]==')') 1L else 0L
                }else{
                    if(s[it]=='(') 1L else 0L
                }
            })
        }else{
            println(-1)
        }
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