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

fun solve() {
    var n = readInt();
    var a = readInts();
    var sum = 0;
    var smallest_pos = INF;
    var largest_neg = -INF;

    var ans = BooleanArray(n){ false };
    for (i in 0 until n) {
        if (a[i] == 0) continue;
        if (a[i] < 0) largest_neg = max(largest_neg, a[i]);
        if (a[i] > 0) {
            sum += a[i];
            smallest_pos = min(smallest_pos, a[i]);
            ans[i] = true;
        }
    }
    smallest_pos = -smallest_pos;
    for (i in 0 until n) {
        if (smallest_pos >= largest_neg && a[i] == -smallest_pos) {
            ans[i] = false;
            break;
        }
        if (smallest_pos < largest_neg && a[i] == largest_neg) {
            ans[i] = true;
            break;
        }
    }
    var tot = 0;
    for (i in 0 until n) {
        if (ans[i]) {
            tot += a[i];
        }
    }
    println(tot);
    var pr = StringBuilder();
    for (i in 0 until n) {
        if (ans[i]) pr.append('1');
        else pr.append('0');
    }
    println(pr);
}
fun main() {
    val T = readInt();
//    val T = 1;
    repeat(T) {
        solve();
    }
}