// taken from purplecrayon
import java.util.*


/** IO */
//@JvmField val ONLINE_JUDGE = System.getProperty("ONLINE_JUDGE") != null
//const val PATH = "src/main/resources/"
//@JvmField val INPUT = File(PATH + "input.txt").inputStream()
//@JvmField val OUTPUT = File(PATH + "output.txt").outputStream()
@JvmField
val INPUT = System.`in`
@JvmField
val OUTPUT = System.out

const val _BUFFER_SIZE = 1 shl 16
@JvmField
val _buffer = ByteArray(_BUFFER_SIZE)
@JvmField
var _bufferPt = 0
@JvmField
var _bytesRead = 0

tailrec fun readChar(): Char {
    if (_bufferPt == _bytesRead) {
        _bufferPt = 0
        _bytesRead = INPUT.read(_buffer, 0, _BUFFER_SIZE)
    }
    return if (_bytesRead < 0) Char.MIN_VALUE
    else {
        val c = _buffer[_bufferPt++].toChar()
        if (c == '\r') readChar() else c
    }
}

fun readLine(): String? {
    var c = readChar()
    return if (c == Char.MIN_VALUE) null
    else buildString {
        while (c != '\n' && c != Char.MIN_VALUE) {
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

fun solve() {

    var n = readInt();
    var m = TreeMap<Int,Int>();

    for (i in 1..n) {
        var (a, b) = readInts();
        b++;

        var cv = m[a];
        if (cv == null) cv = 0;
        cv++;
        m.put(a, cv);

        cv = m[b];
        if (cv == null) cv = 0;
        cv--;
        m.put(b, cv);

        cv = m[a - 1];
        if (cv == null) cv = 0;
        m.put(a - 1, cv);

        cv = m[b - 1];
        if (cv == null) cv = 0;
        m.put(b - 1, cv);

        cv = m[a + 1];
        if (cv == null) cv = 0;
        m.put(a + 1, cv);

        cv = m[b + 1];
        if (cv == null) cv = 0;
        m.put(b + 1, cv);

    }

    var cv = 0;
    for (i in m) {

        cv += i.value;
        if (cv == 1) {
            println(i.key);
            return;
        }
    }

    println(-1);

}


fun main() {

    var T = readInt();
    while (T --> 0) {
        solve();
    }

}