import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() { _writer.solve(); _writer.flush() }
fun PrintWriter.solve() {
    val T=readInt()
    repeat(T){
        println(readInt()+readInt())
    }
}
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

@JvmField val _reader = INPUT.bufferedReader()
fun readLine(): String? = _reader.readLine()
fun readLn() = _reader.readLine()!!
@JvmField var _tokenizer: StringTokenizer = StringTokenizer("")
fun read(): String {
    while (_tokenizer.hasMoreTokens().not()) _tokenizer = StringTokenizer(_reader.readLine() ?: return "", " ")
    return _tokenizer.nextToken()
}
fun readInt() = read().toInt()
fun readDouble() = read().toDouble()
fun readLong() = read().toLong()
fun readVString(n: Int) = List(n) { read() }
fun readLines(n: Int) = List(n) { readLn() }
fun readVInt(n: Int) = List(n) { read().toInt() }
fun readAInt(n: Int) = IntArray(n) { read().toInt() }
fun readVDouble(n: Int) = List(n) { read().toDouble() }
fun readADouble(n: Int) = DoubleArray(n) { read().toDouble() }
fun readVLong(n: Int) = List(n) { read().toLong() }
fun readALong(n: Int) = LongArray(n) { read().toLong() }

@JvmField val _writer = PrintWriter(OUTPUT, false)
inline fun output(block: PrintWriter.() -> Unit) { _writer.apply(block).flush() }

// old
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
//fun read() = readl()
fun readV() = readVl()