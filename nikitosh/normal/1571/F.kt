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
    val (n, m) = readInts()
    var k = IntArray(n)
    var t = IntArray(n)
    var sumK = 0
    var sumK2 = 0
    for (i in 0..n - 1) {
        val (kk, tt) = readInts()
        k[i] = kk
        t[i] = tt
        sumK += kk
        if (tt == 2) {
            sumK2 += kk
        }
    }
    var pr = IntArray(m + 1)
    for (i in 1..m)
        pr[i] = -1
    pr[0] = 0
    if (sumK > m) {
        println(-1)
        return
    }
    for (i in 0..n - 1) {
        if (t[i] == 1) 
            continue
        for (j in m downTo 0)
            if (pr[j] != -1 && j + k[i] <= m && pr[j + k[i]] == -1) {
                pr[j + k[i]] = i + 1; 
            }
    }
    var ans = IntArray(n)
    for (i in ((sumK2 + 1) shr 1)..sumK2) {
        if (pr[i] != -1) {
            var st = max(i * 2 - 1, (sumK2 - i) * 2)
            if (st + sumK - sumK2 > m) {
                println(-1)
            } else {
                var curDay = 1
                var cur = i
                while (cur != 0) {
                    val p = pr[cur] - 1
                    cur -= k[p]
                    ans[p] = curDay
                    curDay += 2 * k[p]
                }
                var curDay2 = 2
                for (j in 0..n - 1) {
                    if (ans[j] != 0) {
                        print(ans[j])
                    } else {
                        if (t[j] == 1) {
                            print(st + 1)
                            st += k[j]
                        } else {
                            print(curDay2)
                            curDay2 += 2 * k[j]
                        }
                    }
                    print(' ')
                }
            }
            break
        }
    }
}