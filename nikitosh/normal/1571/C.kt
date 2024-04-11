import kotlin.math.min
import kotlin.math.max
import java.io.*
import java.util.*
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles

fun main(args: Array<String>) {
    repeat(readInt()) {
        val n = readInt()
        var l = 0
        var r = 200000
        for (i in 0..n-1) {
            val (s, t, rr) = readStrings()
            val mark = rr.toInt()
            val sRev = s.reversed()
            val tRev = t.reversed()
            val len = min(s.length, t.length)
            var pr = len
            for (j in 0..len-1)
                if (sRev[j] != tRev[j]) {
                    pr = j
                    break
                }
            if (mark == 0) {
                l = max(l, pr + 1)    
            } else {
                r = min(r, pr)    
            }
        }
        if (l > r)
            l = r + 1
        println(r - l + 1)
        for (i in l..r) {
            print(i)
            print(' ')
        }
        println()
    }

}