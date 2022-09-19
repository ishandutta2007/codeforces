@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.Math.max
import java.lang.Math.min
import java.util.*

private fun solve() {
    var (n, m, K) = readInts()
    var a = readLongs(n)
    var b = readLongs(m)
    var c = Array(n) {
        readLongs(m)
    }
    var e = Array(n * m) { Pair(0L, 0L) }
    var mx = longarr(m)
    for (i in 0 until n) {
        var mmx = 0L
        for (j in 0 until m) {
            mx[j] = Math.max(mx[j], c[i][j])
            mmx = Math.max(mmx, mx[j])
            var x = Math.max(a[i], b[j])
            e[i * m + j] = Pair(x, mmx)
        }
    }
    e.sortBy { x -> x.first }
    var ee = ArrayList<Pair<Long, Long>>()
    for (q in e) {
        if (ee.size == 0 || q.first != ee.last().first) {
            ee.add(q)
        } else if (q.second > ee.last().second) {
            ee[ee.size - 1] = q
        }
    }
//    println(ee)
    var nn = ee.size
    var d1 = longarr(nn, Long.MAX_VALUE)
    var d2 = longarr(nn)
    var d1k = longarr(nn, Long.MAX_VALUE)
    var d2k = longarr(nn)
    d1[0] = 0
    d1k[0] = 0
    for (i in 0 until nn) {
        for (j in i + 1 until nn) {
            var d = Math.max(ee[j].first - d2[i], 0L)
            var k = (d + ee[i].second - 1) / ee[i].second
            var dd1 = d1[i] + k
            var dd2 = d2[i] + k * ee[i].second
            if (dd1 < d1[j] || dd1 == d1[j] && dd2 > d2[j]) {
                d1[j] = dd1
                d2[j] = dd2
            }
            d = Math.max(ee[j].first - d2[i], 0L)
            k = (d + ee[i].second + K - 1) / (ee[i].second + K)
            dd1 = d1[i] + k
            dd2 = d2[i] + k * (ee[i].second + K)
            if (dd1 < d1k[j] || dd1 == d1k[j] && dd2 > d2k[j]) {
                d1k[j] = dd1
                d2k[j] = dd2
            }
            d = Math.max(ee[j].first - d2k[i], 0L)
            k = (d + ee[i].second - 1) / ee[i].second
            dd1 = d1k[i] + k
            dd2 = d2k[i] + k * ee[i].second
            if (dd1 < d1k[j] || dd1 == d1k[j] && dd2 > d2k[j]) {
                d1k[j] = dd1
                d2k[j] = dd2
            }
        }
    }
    println(d1k[nn - 1])
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

private fun println(a: LongArray) {
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