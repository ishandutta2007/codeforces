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

const val INF = (1e9).toInt()+10;

fun lower_bound(x: Int, a: MutableList<Int>): Int {
    var lo = -1;
    var hi = a.size;
    var mid = (lo+hi)/2;
    while (lo < mid && mid < hi) {
        if (a[mid] >= x) hi = mid;
        else lo = mid;
        mid = (lo+hi)/2;
    }
    return hi;
}
fun nxt(c: Int, a: MutableList<Int>, k: Int, n: Int): Int {
    var i = lower_bound(c, a);
    if (i+k >= a.size) return n;
    return a[i+k];
}
fun solve() {
    var s = readLn();
    var n = s.length;
    var loc0 = mutableListOf<Int>();
    var loc1 = mutableListOf<Int>();
    for (i in 0 until n) {
        if (s[i] == '0') {
            loc0.add(i);
        } else {
            loc1.add(i);
        }
    }

    var pr = StringBuilder();
    for (i in 1 until n+1) {
        var c = 0;
        var ans = 0;
        while (c < n) {
            var nxt0 = nxt(c, loc0, i, n);
            var nxt1 = nxt(c, loc1, i, n);
            var nxt = max(nxt0, nxt1);
            c = nxt;
            ans++;
        }
        if (pr.length > 0) pr.append(" ");
        pr.append(ans);
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