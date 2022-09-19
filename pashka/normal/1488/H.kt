@file:Suppress("CanBeVal")

import java.io.BufferedReader
import java.io.InputStreamReader
import java.io.OutputStreamWriter
import java.io.PrintWriter
import java.util.*

val MOD = 998244353L

internal class Item {
    val a = intarr(16);
    fun add(item: Item): Item {
        if (this == NEUTRAL) return item
        if (item == NEUTRAL) return this
        val res = Item()
        for (i in 0 until 4) {
            for (j in 0 until 4) {
                for (k in 0 until 4) {
                    res.a[i * 4 + j] = ((res.a[i * 4 + j] +
                            1L * this.a[i * 4 + k] * item.a[k * 4 + j]) % MOD).toInt()
                }
            }
        }
        return res
    }
}

private val NEUTRAL = Item()

internal class SegmentTree(private val size: Int) {
    private val a: Array<Item>

    operator fun set(i: Int, v: Item) {
        set(0, 0, size, i, v)
    }

    private operator fun set(n: Int, l: Int, r: Int, i: Int, v: Item) {
        if (r == l + 1) {
            a[n] = v
        } else {
            val m = (l + r) / 2
            if (i < m) {
                set(n * 2 + 1, l, m, i, v)
            } else {
                set(n * 2 + 2, m, r, i, v)
            }
            a[n] = a[n * 2 + 1].add(a[n * 2 + 2])
        }
    }

    fun sum(l: Int, r: Int): Item {
        return sum(0, 0, size, l, r)
    }

    private fun sum(n: Int, ll: Int, rr: Int, l: Int, r: Int): Item {
        return if (ll >= l && rr <= r) {
            a[n]
        } else if (ll >= r || l >= rr) {
            NEUTRAL
        } else {
            val m = (ll + rr) / 2
            sum(n * 2 + 1, ll, m, l, r).add(sum(n * 2 + 2, m, rr, l, r))
        }
    }

    init {
        a = Array<Item>(4 * size) { NEUTRAL }
    }
}

private fun build(a: Int, b: Int): Item {
    val res = Item()
    if (a == 0) {
        for (i in 0 until 4) {
            for (j in i + 1 until 4) {
                res.a[i * 4 + j] = 1
            }
            if (b == 0) {
                res.a[i * 4 + i] = 1
            }
        }
    } else {
        for (i in 0 until 4) {
            for (j in 0 until i) {
                res.a[i * 4 + j] = 1
            }
            if (b == 1) {
                res.a[i * 4 + i] = 1
            }
        }
    }
    return res
}

private fun solve() {
    var (n, q) = readInts()
    var a = intarr(n)
    for (i in 0 until n - 1) {
        a[i] = readInt()
    }
    val st = SegmentTree(n - 1)
    for (i in 0 until n - 1) {
        st.set(i, build(a[i], a[i + 1]))
    }
    while (q --> 0) {
        var x = readInt()
        x--
        a[x] = 1 - a[x]
        st.set(x, build(a[x], a[x + 1]))
        if (x > 0) {
            st.set(x - 1, build(a[x - 1], a[x]))
        }
        val s = st.sum(0, n - 1)
        var res = 0L
        for (i in 0 until 4) {
            for (j in 0 until 4) {
                res += s.a[i * 4 + j]
                res %= MOD
            }
        }
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