import kotlin.math.*;
import java.util.*;
import kotlin.system.exitProcess
import java.io.BufferedInputStream;

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

const val INF = (2e9).toInt()+10;

fun solve() {
    var n = readInt();
    var a = readInts().toIntArray();
    var b = readInts().toIntArray();
    a.sort(); b.sort();
    var pre = IntArray(n){ -INF };
    var suf = IntArray(n){ -INF };
    for (i in 0 until n) {
        if (i > 0) pre[i] = pre[i-1];
        pre[i] = max(pre[i], b[i]-a[i]);
    }
    for (i in n-1 downTo 0) {
        if (i < n-1) suf[i] = suf[i+1];
        suf[i] = max(suf[i], b[i+1]-a[i]);
    }
    fun lower_bound(x: Int): Int {
        var lo = -1;
        var hi = n;
        var mid = (lo+hi)/2;
        while (lo < mid && mid < hi) {
            if (a[mid] >= x) hi = mid;
            else lo = mid;
            mid = (lo+hi)/2;
        }
        return hi;
    }
    var q = readInt();
    var pr = StringBuilder();

    var qs = readInts();
    repeat(q) {
        var x = qs[it];
        var idx = lower_bound(x);

        var ans = -INF;
        if (idx > 0) ans = max(ans, pre[idx-1]);
        if (idx < n) ans = max(ans, suf[idx]);

        ans = max(ans, b[idx]-x);

        if (pr.length > 0) pr.append(" ");
        pr.append(ans.toString());
    }
    println(pr);
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}