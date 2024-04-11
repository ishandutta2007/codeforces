@file:Suppress("CanBeVal")
import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.RuntimeException
import java.util.*

private fun solve() {
//    var rnd = Random()
//    while (true) {
//        var k = 1 + rnd.nextInt(5)
//        var n = 1 + rnd.nextInt(5)
//        var p = Array<Int>(k) {1 + rnd.nextInt(10)}
//        Arrays.sort(p)
//        var x = Array<Int>(n) {-1}
//        var z = BooleanArray(100000)
//        var x1 = rnd.nextInt(10) + 1
//        var x2 = rnd.nextInt(10) + 1
//        var p1 = p[rnd.nextInt(k)]
//        var p2 = p[rnd.nextInt(k)]
//        for (i in 0 until n) {
//            while (x[i] == -1 || z[x[i]]) {
//                if (rnd.nextBoolean()) {
//                    x[i] = x1 + rnd.nextInt(10) * p1
//                } else {
//                    x[i] = x2 + rnd.nextInt(10) * p2
//                }
//            }
//            z[x[i]] = true;
//        }
//        Arrays.sort(x)
//        solve(k, n, p, x)
//    }
    var (k, n) = readInts()
    var p = readInts(k)
    var x = readInts(n)
    solve(k, n, p, x)
}

private fun solve(k: Int, n: Int, p: Array<Int>, x: Array<Int>) {
    var d = intarr(n)
    val MAX = 1000005
    var id = intarr(MAX, -1)
    for (i in 0 until n) {
        id[x[i]] = i
    }
    for (i in 1 until n) {
        d[i] = x[i] - x[i - 1]
    }
    var p2 = 1
    var pp = 0
    var logs = intarr(n + 1)
    for (i in 1 until n + 1) {
        if (p2 * 2 <= i) {
            p2 *= 2
            pp++
        }
        logs[i] = pp
    }
    var st = intarr2d(20, n)
    for (i in 0 until n) {
        st[0][i] = d[i]
    }
    for (k in 1 until 20) {
        for (i in 0 until n) {
            if (i + (1 shl k) > n) break
            st[k][i] = gcd(st[k - 1][i], st[k - 1][i + (1 shl (k - 1))])
        }
    }

    var good = intarr(MAX, -1)
    for (i in 0 until k) {
        good[p[i]] = p[i]
    }
    for (i in 0 until MAX) {
        if (good[i] != -1) {
            var x = i
            while (x < MAX) {
                if (good[x] == -1) {
                    good[x] = good[i]
                }
                x += i
            }
        }
    }
    good[0] = p[0]
    for (p1 in p) {
        var c = x[0]
        var ll = 0
        var d = 0
        var x0 = -1
        while (c + p1 < MAX) {
            c += p1
            if (id[c] != -1) {
                var rr = id[c]
                if (rr > ll + 1) {
                    if (x0 == -1) {
                        x0 = x[ll + 1]
                    } else {
                        d = gcd(d, x[ll + 1] - x0)
                    }
                    if (rr > ll + 2) {
                        var len = rr - ll - 2
                        var k = logs[len]
                        d = gcd(d, st[k][ll + 2])
                        d = gcd(d, st[k][rr - (1 shl k)])
                    }
                }
//                println(listOf(x[ll], x[rr], d, x0))
                ll = rr
            }
        }
        var rr = n
        if (rr > ll + 1) {
            if (x0 == -1) {
                x0 = x[ll + 1]
            } else {
                d = gcd(d, x[ll + 1] - x0)
            }
            if (rr > ll + 2) {
                var len = rr - ll - 2
                var k = logs[len]
                d = gcd(d, st[k][ll + 2])
                d = gcd(d, st[k][rr - (1 shl k)])
            }
        }
        if (x0 == -1) {
            println("YES")
            println(listOf(x[0], p1))
            println(listOf(x[0], p1))
            return
        }
        if (good[d] != -1) {
            println("YES")
            println(listOf(x[0], p1))
            println(listOf(x0, good[d]))
            var dd = good[d]
            for (i in 0 until n) {
                if (((x[i] - x[0]) % p1 != 0) &&
                        ((x[i] - x0) % dd != 0)) {
                            throw RuntimeException()
                        }
            }
            return
        }
    }
//    println(n)
//    println(k)
//    println(p)
//    println(x)
//    throw RuntimeException()
    println("NO")
}

fun gcd(aa: Int, bb: Int): Int {
    var a = aa
    var b = bb
    while (b > 0) {
        var c = a % b
        a = b
        b = c
    }
    return a
}

// TEMPLATE
fun main(args: Array<String>) {
    reader = BufferedReader(InputStreamReader(System.`in`))
    out = PrintWriter(OutputStreamWriter(System.out))
    try {
        solve()
    } finally {
        out.close()
    }
}

private lateinit var out: PrintWriter
private lateinit var reader: BufferedReader
private var tokenizer: StringTokenizer? = null
private fun read(): String {
    while (tokenizer == null || !tokenizer!!.hasMoreTokens()) {
        tokenizer = StringTokenizer(readLn())
    }
    return tokenizer!!.nextToken()
}

private fun readInt() = read().toInt()
private fun readLong() = read().toLong()
private fun readLn() = reader.readLine()!!
private fun readInts() = readLn().split(" ").map { it.toInt() }
private fun readInts(sz: Int) = Array(sz) { readInt() }
private fun readLongs() = readLn().split(" ").map { it.toLong() }
private fun readLongs(sz: Int) = Array(sz) { readLong() }
private fun print(b: Boolean) = out.print(b)
private fun print(i: Int) = out.print(i)
private fun print(d: Double) = out.print(d)
private fun print(l: Long) = out.print(l)
private fun print(s: String) = out.print(s)
private fun print(message: Any?) = out.print(message)
private fun print(a: Array<Int>) = a.forEach { print("$it ") }
private fun <T> print(a: Array<out T>) = a.forEach { print("$it ") }
private fun <T> print(a: Collection<T>) = a.forEach { print("$it ") }
private fun println(b: Boolean) = out.println(b)
private fun println(i: Int) = out.println(i)
private fun println(d: Double) = out.println(d)
private fun println(l: Long) = out.println(l)
private fun println(s: String) = out.println(s)
private fun println() = out.println()
private fun println(message: Any?) = out.println(message)
private fun <T> println(a: Array<out T>) {
    a.forEach { print("$it ") }
    println()
}
private fun println(a: IntArray) {
    a.forEach { print("$it ") }
    println()
}
private fun <T> println(a: Collection<T>) {
    a.forEach { print("$it ") }
    println()
}
private fun intarr(sz: Int, v: Int = 0) = IntArray(sz) { v }
private fun longarr(sz: Int, v: Long = 0) = LongArray(sz) { v }
private fun intarr2d(n: Int, m: Int, v: Int = 0) = Array(n) { intarr(m, v) }
private fun <T> init(vararg elements: T) = elements
private fun VI(n: Int = 0, init: Int = 0) = MutableList(n) { init }
private fun VVI(n: Int = 0, m: Int = 0, init: Int = 0) = MutableList(n) { VI(m, init) }
private fun <T1 : Comparable<T1>, T2 : Comparable<T2>> pairCmp(): Comparator<Pair<T1, T2>> {
    return Comparator { a, b ->
        val res = a.first.compareTo(b.first)
        if (res == 0) a.second.compareTo(b.second) else res
    }
}