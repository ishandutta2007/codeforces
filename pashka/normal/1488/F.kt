@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.Math.abs
import java.lang.Math.min
import java.util.*

private fun solve() {
    var n = readInt()
    var c = readLongs(n)
    var st = intarr(n)
    var sp = 0
    val MAX = 20
    var jmp = intarr2d(MAX, n, -1)
    var sums = longarr2d(MAX, n, -1)
    for (i in 0 until n) {
        while (sp > 0) {
            if (c[st[sp - 1]] > c[i]) {
                jmp[0][i] = st[sp - 1]
                sums[0][i] = c[i] * (i - st[sp - 1])
                break
            } else {
                sp--
            }
        }
        if (sp == 0) {
            jmp[0][i] = -1
            sums[0][i] = c[i] * (i + 1)
        }
        st[sp++] = i
//        println("" + jmp[0][i] + " " + sums[0][i])
    }
    for (j in 1 until MAX) {
        for (i in 0 until n) {
            val xx = jmp[j - 1][i]
            if (xx == -1) {
                jmp[j][i] = -1
                sums[j][i] = sums[j - 1][i]
            } else {
                jmp[j][i] = jmp[j - 1][xx]
                sums[j][i] = sums[j - 1][i] + sums[j - 1][xx]
            }
        }
    }

    var q = readInt()
    while (q --> 0) {
        var (l, r) = readInts()
        l--
        r--
        var x = r
        var res = 0L
        for (j in MAX - 1 downTo 0) {
            if (jmp[j][x] >= l) {
                res += sums[j][x]
                x = jmp[j][x];
            }
        }
        res += c[x] * (x - l + 1)
        println(res)
    }
}

// TEMPLATE
fun main(args: Array<String>) {
    reader = BufferedReader(InputStreamReader(System.`in`))
    out = PrintWriter(OutputStreamWriter(System.out))
    solve()
    out.close()
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
private fun longarr2d(n: Int, m: Int, v: Long = 0) = Array(n) { longarr(m, v) }
private fun <T> init(vararg elements: T) = elements
private fun VI(n: Int = 0, init: Int = 0) = MutableList(n) { init }
private fun VVI(n: Int = 0, m: Int = 0, init: Int = 0) = MutableList(n) { VI(m, init) }
private fun <T1 : Comparable<T1>, T2 : Comparable<T2>> pairCmp(): Comparator<Pair<T1, T2>> {
    return Comparator { a, b ->
        val res = a.first.compareTo(b.first)
        if (res == 0) a.second.compareTo(b.second) else res
    }
}