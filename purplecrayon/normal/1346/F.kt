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

const val INF = (1e18).toLong()+10;
fun solve() {
    var (n, m, q) = readInts();

    var prv = Array<LongArray>(n){ LongArray(m){ 0; }; };
    var a = LongArray(n){ 0; };
    var b = LongArray(m){ 0; };
    for (i in 0 until n) {
        var r = readLongs();
        for (j in 0 until m) {
            a[i] += r[j];
            b[j] += r[j];

            prv[i][j] = r[j];
        }
    }
    fun get(x: LongArray): Long {
        var c = x.size;
        var p = LongArray(c){ 0; }

        var sm = 0L;
        var tot = 0L;
        for (i in 0 until c) {
            sm += x[i];
            tot += i*x[i];

            p[i] += sm*i-tot;
        }

        sm = 0L;
        tot = 0L;
        for (i in c-1 downTo 0) {
            sm += x[i];
            tot += i*x[i];

            p[i] += tot-sm*i;
        }
        var ans = INF;
        for (i in 0 until c) {
            ans = min(ans, p[i]);
        }
        return ans;
    }

    var ans = StringBuilder((get(a)+get(b)).toString());
    for (i in 0 until q) {
        ans.append(" ");
        var (i, j, x) = readInts();
        i--; j--;

        a[i] -= prv[i][j];
        a[i] += x.toLong();
        b[j] -= prv[i][j];
        b[j] += x.toLong();

        prv[i][j] = x.toLong();

        ans.append((get(a)+get(b)).toString());
    }
    println(ans);
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}