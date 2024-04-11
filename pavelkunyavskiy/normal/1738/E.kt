import kotlin.math.*

private const val MOD = 998244353
@JvmInline
private value class ModInt(val x:Int) {
    operator fun plus(other: ModInt) = ModInt((x + other.x).let { if (it >= MOD) it - MOD else it })
    operator fun minus(other: ModInt) = ModInt((x - other.x).let { if (it < 0) it + MOD else it })
    operator fun times(other: ModInt) = ModInt((x.toLong() * other.x % MOD).toInt())
    fun power(p_: Int) : ModInt {
        var a = this
        var res = ModInt(1)
        var p = p_
        while (p != 0) {
            if ((p and 1) == 1) res *= a
            a *= a
            p = p shr 1
        }
        return res
    }
    operator fun div(other: ModInt) = this * other.power(MOD - 2)
}
@JvmInline
private value class ModIntArray(private val storage:IntArray) {
    operator fun get(index: Int) = ModInt(storage[index])
    operator fun set(index: Int, value: ModInt) { storage[index] = value.x }
    val size get() = storage.size
}
private inline fun ModIntArray(n: Int, init: (Int) -> ModInt) = ModIntArray(IntArray(n) { init(it).x })

private const val MAX = 110_000
private val f = ModIntArray(MAX) { ModInt(1) }.apply {
    for (i in 2 until size) {
        set(i, get(i - 1) * ModInt(i))
    }
}
private val invf = ModIntArray(MAX) { ModInt(1) / f[it] }

private fun cnk(n: Int, k:Int) : ModInt = f[n] * invf[k] * invf[n - k]
private fun getGroup(a: Int, b: Int) = (0..min(a, b)).fold(ModInt(0)) { acc, it -> acc + cnk(a, it) * cnk(b, it) }
private fun getGroup(a: Int) = ModInt(2).power(a - 1)
private fun solve() {
    val n = readInt()
    val a = readLongs().toLongArray()
    var l = 0
    var r = n
    var ans = ModInt(1)
    while (r - l > 1) {
        if (a[l] == a[r - 1]) {
            val ll = l
            val rr = r
            l++
            r--
            while (l < r && a[l] == 0L) l++
            while (l < r && a[r - 1] == 0L) r--
            ans *= if (l == r) {
                getGroup(rr - ll)
            } else {
                getGroup(l - ll, rr - r)
            }
        } else if (a[l] < a[r - 1]) {
            a[l + 1] += a[l]
            l++
        } else {
            a[r - 2] += a[r - 1]
            r--
        }
    }
    println(ans.x)
}

fun main() {
    repeat(readInt()) {
        solve()
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }