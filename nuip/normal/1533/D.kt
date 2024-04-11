import java.io.PrintWriter
import java.util.*
import kotlin.collections.HashMap

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    val n=readInt()
    val m=readInt()
    val ss=readVString(n).sorted()
    val q=readInt()
    val qs=readVString(q)
    println(qs.map { s ->
        var re = 0
        for (i in 0..m) {
            if (i > 0 && s[i - 1] == s[i]) continue
            if (ss.binarySearch(s.substring(0, i) + s.substring(i + 1)) >= 0) ++re
        }
        re
    }.joinToString(" "))
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