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

const val MOD = 998244353;

fun add(a: Int, b: Int): Int {
    var c = a + b
    if (c >= MOD)
        return c - MOD
    return c
}

fun sub(a: Int, b: Int): Int {
    var c = a - b
    if (c < 0)
        return c + MOD
    return c
}

fun mul(a: Int, b: Int): Int {
    return ((a.toLong() * b.toLong()) % MOD).toInt()
}

fun power(a: Int, n: Int): Int {
    if (n == 0)
        return 1
    var b = power(a, n / 2)
    b = mul(b, b)
    if (n % 2 == 0)
        return b
    return mul(b, a)
}

fun rev(a: Int): Int{
    return power(a, MOD - 2)
}

fun main(args: Array<String>) {
    val (n, a, b) = readInts()
    var cnt1 = IntArray(a + b + 1) { 1 };
    var cnt2 = IntArray(a + b + 1) { 1 };
    
    var xxxs = mutableListOf(0);
    var yyys = mutableListOf(0);
    for (i in 0..n - 1) {
        val (x, y, p) = readInts()
        val realP = mul(p, rev(1000000))
        cnt1[x + y] = mul(cnt1[x + y], sub(1, realP))
        cnt2[y - x + a] = mul(cnt2[y - x + a], sub(1, realP))
        xxxs.add(x)
        yyys.add(y)
    }
    xxxs.add(a)
    yyys.add(b)
    var xxs = xxxs.sorted()
    var yys = yyys.sorted()
    var xs = xxs.distinct()
    var ys = yys.distinct()
    
    var ans = 0
    for (i in 0..xs.size - 2) {
        var xL = xs[i]
        var xR = xs[i + 1]
        for (j in 0..ys.size - 2) {
            var yL = ys[j]
            var yR = ys[j + 1]
            ans = add(ans, 1)
            var sumX = 0
            var sumY = 0
            for (g in xL + yL + 1..xR + yR - 1)
                sumX = add(sumX, sub(1, cnt1[g]))
            for (g in yL - xR + a + 1..yR - xL + a - 1)
                sumY = add(sumY, sub(1, cnt2[g]))
            for (g1 in xL + 1 .. xR)
                for (g2 in yL + 1 .. yR) {
                    if (g1 != xR && g2 != yR)
                        ans = add(ans, mul(sub(1, cnt1[g1 + g2]), sub(1, cnt2[g2 - g1 + a])))
                    ans = add(ans, mul(sub(1, cnt1[g1 + g2 - 1]), sub(1, cnt2[g2 - g1 + a])))
                }
            ans = add(ans, sumX)
            ans = add(ans, sumY)
        }
    }
    println(ans)
}