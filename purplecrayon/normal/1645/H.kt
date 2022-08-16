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

val INF = (1e9+10).toInt();

fun solve() {
    var n = readInt();
    var a = readInts();
    var inc = -INF;
    var dec = INF;
    var ans = MutableList<Int>(n){ -1 };
    for (i in 0 until n) {
        var x = a[i];
        if (x > inc && x < dec) {
            if (i == n-1 || a[i+1] > a[i]) { inc = x; ans[i] = 0; }
            else { dec = x; ans[i] = 1; }
        } else if (x > inc) {
            inc = x;
            ans[i] = 0;
        } else if (x < dec) {
            dec = x;
            ans[i] = 1;
        } else {
            println("NO");
            return;
        }
    }
    println("YES");
    println(ans.joinToString(" "));
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}