import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    val n=readInt()
    val m=readInt()
    val mp=readVString(n)
//    val mp=List(n){i-> List(m){('A'+i%5)}.joinToString("") }
    val cnts=LongArray(32){0L}
    for(st in 0..31) {
        val hs = IntArray(m){0}
        val stk = IntArray(m){0}
        for(i in 0..n-1) {
            var stki=0
            var sum=0L
            for(j in 0..m-1) {
                ++hs[j]
                if(((st shr (mp[i][j]-'A')) and 1)==0) hs[j]=0
                while(stki>0 && hs[stk[stki-1]]>=hs[j]){
                    val t = stk[stki-1]
                    --stki
                    sum-=hs[t].toLong()*(t-(if(stki==0) -1 else stk[stki-1]))
                }
                sum+=hs[j].toLong()*(j-(if(stki==0) -1 else stk[stki-1]))
                stk[stki]=j
                ++stki
                cnts[st]+=sum
            }
        }
    }
//    println(cnts)
    for(st in 0..31)for(sup in st+1..31)if((st and sup)==st) cnts[sup]-=cnts[st]
//    println(cnts)
    val re= MutableList(6){0L}
    for(st in 0..31) re[(0..4).count { ((st shr it) and 1)==1 }]+=cnts[st]
    println(re.subList(1,6).joinToString(" "))
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