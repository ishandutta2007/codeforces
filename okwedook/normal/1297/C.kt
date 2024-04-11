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
	var a = ArrayList<Int>();
	for (i in 0..n - 1) a.add(sc.nextInt());
	var neg = ArrayList<Int>();
	var pos = ArrayList<Int>();
	for (a in a) {
		if (a < 0) neg.add(a);
		else if (a > 0) pos.add(a);
	}
	var sum = 0;
	for (a in pos) sum += a;
	var mx = -1e9.toInt();
	for (a in neg) mx = max(mx, a);
	var mn = 100000;
	for (a in pos) mn = min(mn, a);
	pr.println(max(sum - mn, sum + mx));
	if (sum + mx > sum - mn) {
	    var flag = true;
	    for (i in 0..n - 1) {
	        if (a[i] > 0) pr.print(1);
	        else {
	            if (a[i] == mx && flag) {
	                pr.print(1);
	                flag = false;
	            } else {
	                pr.print(0);
	            }
	        }
	    }
	} else {
	    var flag = true;
	    for (i in 0..n - 1) {
	        if (a[i] > 0) {
	            if (a[i] == mn) {
	                if (flag) {
	                    pr.print(0);
	                    flag = false;
	                } else {
	                    pr.print(1);
	                }
	            } else {
	                pr.print(1);
	            }
	        } else {
	            pr.print(0);
	        }
	    }
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