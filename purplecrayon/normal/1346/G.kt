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

fun getDiv(x: Int): MutableList<Int> {
    var a = mutableListOf<Int>();
    var j = 1L;
    while (j*j <= x) {
        if (x%j.toInt() == 0) {
            a.add(j.toInt());
            if (j.toInt() != x/j.toInt()) a.add(x/j.toInt());
        }
        j++;
    }
    return a;
}
tailrec fun gcd(x: Int, y: Int): Int {
    if (y == 0) return x;
    return gcd(y, x%y);
}
fun solve() {
    var (k, n) = readInts();
    var pp = readInts();
    var x = readInts();

    if (n <= 2){
        println("YES");
        var s1 = x[0];
        var p1 = pp[0];
        var s2 = x[1];
        var p2 = pp[0];
        println("$s1 $p1");
        println("$s2 $p2");
        exitProcess(0);
    }
    fun test(s: Int, p: Int) {
        var a = mutableListOf<Int>();
        for (i in 0 until n) {
            if (x[i]%p != s%p || x[i] < s) a.add(x[i]);
        }
        if (a.size == 0) {
            println("YES");
            println("$s $p")
            println("$s $p")
            exitProcess(0);
        }
        var g = 0;
        for (i in 1 until a.size) {
            g = gcd(a[i]-a[i-1], g);
        }
        for (_i in 0 until k) {
            var i = pp[_i];
            if (g%i == 0) {
                println("YES");
                println("$s $p");

                var s2 = a[0];
                var p2 = i;
                println("$s2 $p2");
                exitProcess(0);
            }
        }
    }
    fun get(s: Int, div: Int) {
//        println("try: $s $div")
        for (x in getDiv(div)) {
            var bad = true
            for (i in pp) if (i == x) bad = false;
            if (!bad) test(s, x);
        }
    }
    get(x[0], x[1]-x[0]);
    get(x[0], x[2]-x[0]);
    get(x[1], x[2]-x[1]);
    println("NO");
}
fun main() {
//    val T = readInt();
    val T = 1;
    repeat(T) {
        solve();
    }
}