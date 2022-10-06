import java.io.PrintWriter
import java.util.*

val pw = PrintWriter(System.out)
fun main() {
    _writer.solve(); _writer.flush()
}

fun PrintWriter.solve() {
    val T=readInt()
    repeat(T) {
        val n = readInt()
        val m = readInt()
        val mp = List(n) { readAInt(m) }
        val cnt = mp.map { ar -> ar.count { v -> v > 0 } }.sum()
        val vs = mutableListOf<Int>()
        var si = 0
        var sj = 0
        for (i in 0..n - 1) for (j in 0..m - 1) {
            if (mp[i][j] == 0) continue
            si = i
            sj = j
        }
        dfs(si, sj, mp, vs)
        if (vs.toSet().size != cnt) {
            println(-1)
            return@repeat
        }
        var i1 = (vs.size + 1) / 2
        var i2 = (vs.size + 0) / 2
        println("$i1 $i2")
        println((0..i1 - 1).map { i ->
            (0..i2 - 1).map { j -> vs[i + j] }.joinToString(" ")
        }.joinToString("\n"))
    }
}

val dx= listOf(1,0,-1,0)
val dy= listOf(0,1,0,-1)
fun dfs(r: Int, c: Int, mp: List<IntArray>, re: MutableList<Int>): Boolean {
    if(r<0 || c<0 || r>=mp.size || c>=mp[r].size || mp[r][c]==0) return false
    val v = mp[r][c]
    re.add(v)
    mp[r][c]=0
    for(d in 0..3) if(dfs(r+dy[d],c+dx[d],mp,re)) re.add(v)
    return true
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