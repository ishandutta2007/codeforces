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
        var s = readLn().toCharArray()
        var t = readLn()
        var changed = IntArray(n)
        var differ = IntArray(n)
        var bad = 0
        var ans = 0
        for (i in 0..n - 4) {
            if (t[i] == '1') {
                if (s[i] == ')') {
                    if (changed[i] == 1)
                        bad = 1
                    else {
                        ans += 1
                        s[i] = '('
                    }
                } 
                changed[i] = 1
                if (s[i + 3] == '(') {
                    if (changed[i + 3] == 1)
                        bad = 1
                    else {
                        ans += 1
                        s[i + 3] = ')'
                    }
                }
                changed[i + 3] = 1
                differ[i + 1] = 1
            }  
        }
        if (bad == 1) {
            println(-1)
            return
        }
        for (i in 0..n - 1) {
            if (differ[i] == 1) {
                if (s[i] == s[i + 1]) {
                    ans += 1
                    if (changed[i] == 1 && changed[i + 1] == 1)
                        bad = 1
                    else if (changed[i] == 1)
                        s[i + 1] = ('('.toInt() + ')'.toInt() - s[i + 1].toInt()).toChar()
                    else
                        s[i] = ('('.toInt() + ')'.toInt() - s[i].toInt()).toChar()
                }
            }
        }
        for (i in 0..n - 1) {
            if (differ[i] == 1 && s[i] == s[i + 1])
                bad = 1
        }
        if (bad == 1) {
            println(-1)
            return
        }
        println(ans)
    }
}