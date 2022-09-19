@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.util.*


private fun solveTest() {
    var (n, m) = readInts()
    var a = intarr2d(n, m)
    for (i in 0 until n) {
        var q = readInts(m)
        for (j in 0 until m) {
            a[i][j] = q[j]
        }
    }
    var found = false
    for (i in 0 until n) {
        for (j in 0 until m) {
            if (a[i][j] == 0) continue
            if (found) {
                println(-1)
                return
            }
            found = true
            sz = 0
            dfs(a, i, j)
        }
    }
    var k = (sz + 1) / 2
    println(arrayOf(sz - k, k))
    for (i in 0 until sz - k) {
        for (j in 0 until k) {
            print(p[i + j])
            print(" ")
        }
        println()
    }
}

var p = intarr(1000)
var sz = 0
val dx = arrayOf(-1, 0, 0, 1)
val dy = arrayOf(0, -1, 1, 0)

fun dfs(a: Array<IntArray>, i: Int, j: Int) {
    var k = a[i][j]
    a[i][j] = 0
    p[sz++] = k
    for (d in 0..3) {
        var ii = i + dx[d]
        var jj = j + dy[d]
        if (ii >= 0 && ii < a.size && jj >= 0 && jj < a[0].size && a[ii][jj] != 0) {
            dfs(a, ii, jj)
            p[sz++] = k
        }
    }
}

private fun solve() {
    var t = readInt()
    while (t-- > 0) {
        solveTest()
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