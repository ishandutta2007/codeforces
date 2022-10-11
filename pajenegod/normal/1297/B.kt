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
 
 
fun main() {
    var t = sc.nextLong();
    for (q in 0 .. t - 1)
    {
        var n = sc.nextInt();
        var arrL = ArrayList<Long>();
        var arrR = ArrayList<Long>();
        for (i in 0 .. n - 1)
        {
            arrL.add(sc.nextLong());
            arrR.add(sc.nextLong() + 1.toLong());
        }

        arrL.sort();
        arrR.sort();

        var movies = 0;
        var i = 0;
        var j = 0;
        while (i < n || j < n)
        {
            var x = 0.toLong();
            if (i < n)
                if (j < n && arrL[i] > arrR[j])
                    x = arrR[j];
                else
                    x = arrL[i];
            else
                x = arrR[j];

            while (i < n && arrL.get(i) == x){
                movies += 1;
                i += 1
            }
            
            while (j < n && arrR.get(j) == x){
                movies -= 1;
                j += 1
            }

            if (movies == 1) {
                pr.println(x);
                break;
            }
        }
        if (i == n && j == n)
            pr.println(-1);
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