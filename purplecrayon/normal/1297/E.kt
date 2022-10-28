// taken from purplecrayon
import java.util.*
import kotlin.collections.ArrayDeque
import kotlin.collections.ArrayList


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

    var (n, k) = readInts();
    val g = Array(n) { ArrayList<Int>() }

    for (i in 1..n-1) {
        var (a, b) = readInts();
        a--; b--;
        g[a].add(b);
        g[b].add(a);
    }

    if (n == 2) {
        if (k == 1) {
            print("Yes\n1\n1\n");
            return;
        }
        if (k == 2) {
            print("Yes\n2\n1 2\n");
            return;
        }
        println("No");
        return;
    }

    var root = 0;
    for (i in 0..n-1)
        if (g[i].size > 1)
            root = i;

    var leaves = ArrayDeque<Int>();
    var par = Array<Int>(n) {-1};
    var adj = Array<Int>(n) {0};

    var cv = 0;

    fun dfs(c: Int, l: Int) {
        adj[c] = 0;
        par[c] = l;
        for (i in g[c]) {
            adj[c]++;
            if (i == l) continue;

            dfs(i, c);
        }
        leaves.add(c);
        if (adj[c] == 1)
            cv++;
    }

    dfs(root, -1);

//    for (i in 0..n-1) {
//        print("for $i: ");
//        print(par[i]);
//        print(" ");
//        print(adj[i]);
//        println();
//    }

    if (cv < k) {
        println("No");
        return;
    }

    while (cv > k) {
        var cn = leaves.first();
        leaves.removeFirst();
        cv--;
        var p = par[cn];
        adj[p]--;
        if (adj[p] == 1)
            cv++;
    }

    println("Yes");
    println(leaves.size);
    while (leaves.size > 0) {
        var i = leaves.first() + 1;
        leaves.removeFirst();
        print("$i ");
    }
    println();

}

fun main() {

    var T = readInt();
    while (T --> 0) {
        solve();
    }

}