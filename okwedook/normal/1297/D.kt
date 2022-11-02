import java.util.*
import java.io.*;
import kotlin.*
import java.io.InputStream
import java.lang.NumberFormatException
import java.lang.StringBuilder
import kotlin.system.exitProcess as exit
import kotlin.math.min as min
import kotlin.math.max as max

val sc = FastScanner();
val pr = PrintWriter(System.out);

fun solve() : Int {
	var n = sc.nextInt();
	var k = sc.nextLong();
	var a = ArrayList<Long>();
	for (i in 0..n - 1) a.add(sc.nextLong());
	var b = ArrayList<Pair<Long, Int>>();
	for (i in 0..n - 1) b.add(Pair(a[i], i));
	b.sortWith(compareBy({it.first}, {it.second}));
	b.reverse();
	a.sort();
	a.reverse();
	var l = 0.toLong();
	var r = (2e9 + 100).toLong();
	while (r - l > 1) {
		var m = (l + r) / 2;
		var mx = m;
		var curr = k;
		var flag = true;
		for (a in a) {
			if (mx < a) {
				flag = false;
				break;
			}
			curr -= mx - a;
			--mx;
		}
		if (flag && curr <= 0) r = m;
		else l = m;
	}
	var ans = ArrayList<Long>();
	for (i in 0..n - 1) ans.add(0);
	for (b in b) {
		ans[b.second] = min(k, r - b.first);
		k -= ans[b.second];
	    --r;
	}
	for (ans in ans) {
		pr.print(ans);
		pr.print(' ');
	}
	pr.print('\n');
	return 0;
}
 
fun main() {
    var t = sc.nextLong();
    while (t > 0) {
    	solve();
    	--t;
    }
    pr.close();
}




class FastScanner {
    companion object {
        val input: InputStream = System.`in`
        val buffer = ByteArray(1024) { 0 }
        fun isPrintableChar(c: Int): Boolean = c in 33..126
    }
 
    var ptr = 0
    var buflen = 0
    private fun hasNextByte(): Boolean {
        if (ptr < buflen) {
            return true
        } else {
            ptr = 0
            buflen = input.read(buffer)
            if (buflen <= 0) {
                return false
            }
        }
        return true
    }
 
    private fun readByte(): Int = if (hasNextByte()) buffer[ptr++].toInt() else -1
 
    private fun skipUnprintable() {
        while (hasNextByte() && !isPrintableChar(buffer[ptr].toInt())) ptr++
    }
 
    fun hasNext(): Boolean {
        skipUnprintable()
        return hasNextByte()
    }
 
    fun next(): String {
        if (!hasNext()) throw NoSuchElementException()
        val sb = StringBuilder()
        var b = readByte()
        while (isPrintableChar(b)) {
            sb.appendCodePoint(b)
            b = readByte()
        }
        return sb.toString()
    }
 
    fun nextInt(): Int {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }
 
        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }
 
        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }
 
    fun nextLong(): Long {
        if (!hasNext()) throw NoSuchElementException()
        var n = 0L
        var b = readByte()
        // '-' = 45
        val minus = b == 45
        if (minus) {
            b = readByte()
        }
 
        // '0' = 48 '9' = 57
        if (b !in 48..57) {
            throw NumberFormatException()
        }
 
        while (true) {
            if (b in 48..57) {
                n *= 10
                n += b - 48
            } else if (b == -1 || !isPrintableChar(b)) {
                return if (minus) -n else n
            } else {
                throw NumberFormatException()
            }
            b = readByte()
        }
    }
 
    fun nextDouble(): Double = next().toDouble()
}