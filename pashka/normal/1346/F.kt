@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.Math.abs
import java.lang.Math.min
import java.util.*

private fun solve() {
    var (n, m, q) = readInts()
    var a = Array(n){readInts(m)}
    var sr = longarr(n)
    var sc = longarr(m)
    for (i in 0 until n) {
        for (j in 0 until m) {
            sr[i] = sr[i] + a[i][j]
            sc[j] = sc[j] + a[i][j]
        }
    }
    var pr = longarr(n)
    for (i in 0 until n) {
        var s = 0L
        for (j in 0 until n) {
            s += sr[j] * abs(j - i)
        }
        pr[i] = s
    }
    var pc = longarr(m)
    for (i in 0 until m) {
        var s = 0L
        for (j in 0 until m) {
            s += sc[j] * abs(j - i)
        }
        pc[i] = s
    }
    println(pr.min()!! + pc.min()!!)
    while (q-- > 0) {
        var (x, y, z) = readInts()
        x--
        y--
        for (i in 0 until n) {
            pr[i] = pr[i] + (z - a[x][y]).toLong() * abs(x - i)
        }
        for (i in 0 until m) {
            pc[i] = pc[i] + (z - a[x][y]).toLong() * abs(y - i)
        }
        a[x][y] = z
        println(pr.min()!! + pc.min()!!)
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
private fun <T> init(vararg elements: T) = elements
private fun VI(n: Int = 0, init: Int = 0) = MutableList(n) { init }
private fun VVI(n: Int = 0, m: Int = 0, init: Int = 0) = MutableList(n) { VI(m, init) }
private fun <T1 : Comparable<T1>, T2 : Comparable<T2>> pairCmp(): Comparator<Pair<T1, T2>> {
    return Comparator { a, b ->
        val res = a.first.compareTo(b.first)
        if (res == 0) a.second.compareTo(b.second) else res
    }
}