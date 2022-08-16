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
private fun readLine(): String? {
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

val INF = (2e9+10).toLong();

fun f(n: Long): Long {
    var x = n+1;
    while (x%10 == 0L) x /= 10;
    return x;
}
fun solve() {
    var n = readLong();
    var s = HashSet<Long>();
    while (!s.contains(n)) {
        s.add(n);
        n = f(n);
    }
    println(s.size);
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}