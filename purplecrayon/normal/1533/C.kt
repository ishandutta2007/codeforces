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

fun solve() {
    var (n, k) = readInts();
    var s = readLn();

    var vis = BooleanArray(n){false};
    fun done(): Boolean {
        for (i in 0 until n) {
            if (s[i] == '1' && !vis[i]) return false;
        }
        return true;
    }
    var left = mutableListOf<Int>();
    for (i in 0 until n) left.add(i);

    var c = 0;
    var ans = 0;
    while (!done()) {
        c %= left.size;

        var nxt = c;
        if (c == left.size-1) nxt = 0;
        ans++;
        vis[left[c]] = true;
        left.removeAt(c);

        c = nxt+k-1;
    }
    println(ans);
}
fun main() {
    val T = readInt();
//    val T = 1;
    repeat(T) {
        solve();
    }
}