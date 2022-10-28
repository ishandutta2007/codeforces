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

const val V = 26;
fun solve() {
    var (n, k) = readInts();
    var a = List<MutableList<String>>(n){ _ -> MutableList<String>(k){ _ -> ""; }; };
    var vis = MutableList<Boolean>(V){ _ -> false; };
    repeat(n) {
        var p = readInt();
        for (i in 0 until k) {
            a[p][i] = readLn();
            for (c in a[p][i]) {
                vis[c-'a'] = true;
            }
        }
    }

    var cnt = 0;
    for (i in 0 until V) {
        if (vis[i]) cnt++;
    }

    var b = mutableListOf<String>();
    for (i in 0 until n) {
        for (j in 0 until k) {
            b.add(a[i][j]);
        }
    }

    var adj = List<MutableList<Int>>(V){ _ -> mutableListOf<Int>(); };
    var deg = MutableList<Int>(V){ _ -> 0; };
    for (i in 0 until b.size-1) {
        var bad=true;
        for (j in 0 until min(b[i].length, b[i+1].length)) {
            if (b[i][j] != b[i+1][j]) {
                adj[b[i][j]-'a'].add(b[i+1][j]-'a');
                deg[b[i+1][j]-'a']++;
                bad=false;
                break;
            }
        }
        if (bad && b[i].length > b[i+1].length){
            println("IMPOSSIBLE");
            exitProcess(0);
        }
    }
    var q = mutableListOf<Int>();
    for (i in 0 until V) {
        if (deg[i] == 0 && vis[i]) {
            q.add(i);
        }
    }
    var ptr = 0;
    while (ptr < q.size) {
        var c = q[ptr]; ptr++;
        for (nxt in adj[c]) {
            deg[nxt]--;
            if (deg[nxt] == 0) {
                q.add(nxt);
            }
        }
    }
    if (q.size == cnt) q.forEach { i -> var j = 'a'+i; print(j); };
    else println("IMPOSSIBLE");
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}