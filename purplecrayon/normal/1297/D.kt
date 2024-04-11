import java.lang.Math.*
import java.util.*
import kotlin.math.roundToInt


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField val INPUT = System.`in`
@JvmField val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField var _bufferPt = 0
@JvmField var _bytesRead = 0

tailrec fun readChar(): Char {
    if(_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if(_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}
fun readLine(): String? {
    var c = readChar()
    return if(c == Char.MIN_VALUE) null
    else buildString {
        while(c != '\n' && c != Char.MIN_VALUE) {
            append(c)
            c = readChar()
        }
    }
}
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

val INF = (1e5+10).toInt();

fun ceil_div(x: Long, y: Long): Long {
    return (x+y-1)/y;
}
fun get(a: LongArray, n: Int, i: Int, a_i: Long, _k: Int, p: IntArray) {
    var d = LongArray(n){ 0 };
    var k = _k.toLong();
    for (j in i downTo 0) {
        var end = a_i-(i-j);

        var move = min(end-a[j], k.toLong());
        d[p[j]] = move;
        k -= move;
    }
    println(d.joinToString(" "));
}
fun solve() {
    var (n, k) = readInts();
    var a = readLongs().toTypedArray().toLongArray();

    var _p = IntArray(n){ it };
    val p = _p.sortedBy { a[it] }.toIntArray();
//    println("p: ${p.joinToString(" ")}");

    a.sort();

    var sm = 0L;
    for (i in 0 until n) {
        var dist = a[i]*i.toLong()-sm - i.toLong()*(i.toLong()+1)/2L;
//        println("here $i $dist ${a[i]}")
        if (dist >= k) {
            get(a, n, i, a[i], k, p);
            return;
        }
        var left = k-dist;
        var move_dist = ceil_div(left, (i+1).toLong());
        var new_end = a[i]+move_dist;
        if (i == n-1 || new_end < a[i+1]) {
            get(a, n, i, new_end, k, p);
            return;
        }
        sm += a[i];
    }
}
fun main() {
    val T = readInt();
//    val T = 1;
    repeat(T) {
        solve();
    }
}