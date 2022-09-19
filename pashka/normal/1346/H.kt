@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.lang.Math.max
import java.lang.Math.min
import java.util.*

class Seg(x: Int, y: Int, id: Int) : Comparable<Seg> {
    val x: Int = x
    val y: Int = y
    val id: Int = id
    override fun compareTo(other: Seg): Int {
        if (x != other.x) return Integer.compare(x, other.x)
        if (y != other.y) return Integer.compare(y, other.y)
        return -Integer.compare(id, other.id)
    }
}

private fun solve() {
    var (n, m) = readInts()
    var a = Array(n + m) { readSeg() }
    Arrays.sort(a)
    var res = intarr(n)
    for (t in 0..1) {
        var i = 0
        val MAX = 1000100
        var good = intarr(2 * MAX, -1)
        while (i < a.size) {
            if (a[i].x % 2 == t) {
                var xx = a[i].x
                var later = VI()
                while (i < a.size && a[i].x == xx) {
                    if (a[i].id >= n) {
                        good[a[i].y + 10] = xx
                        if (good[a[i].y + 10 - 4] != -1) {
                            later.add(a[i].y + 10 - 2)
                        }
                        if (good[a[i].y + 10 + 4] != -1) {
                            later.add(a[i].y + 10 + 2)
                        }
                    } else {
                        if (good[a[i].y + 10] == -1) {
                            res[a[i].id] = -1
                        } else {
                            res[a[i].id] = (xx - good[a[i].y + 10]) / 2
                        }
                    }
                    i++
                }
                for (y in later) {
                    good[y] = max(good[y], min(good[y - 2], good[y + 2]))
                }
            } else {
                i++
            }
        }
    }
    println(res)
}

var ids = 0
fun readSeg(): Seg {
    var (l, r) = readInts()
    return Seg(r - l, l + r, ids++)
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