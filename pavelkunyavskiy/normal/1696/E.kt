import kotlin.system.*
import kotlin.time.Duration.Companion.nanoseconds

const val MOD = 1000000007
@JvmInline
value class ModInt(val x:Int) {
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
value class ModIntArray(private val storage:IntArray) {
    operator fun get(index: Int) = ModInt(storage[index])
    operator fun set(index: Int, value: ModInt) { storage[index] = value.x }
    val size get() = storage.size
}
inline fun ModIntArray(n: Int, init: (Int) -> ModInt) = ModIntArray(IntArray(n) { init(it).x })
fun List<ModInt>.toModIntArray() = ModIntArray(size) { get(it) }

fun main() {
    val tm = measureNanoTime {
        readInt()
        val a = readInts().dropLastWhile { it == 0 }.map { it - 1 }
        val N = a.size + (a.maxOrNull() ?: return println(0))
        val fs = (1..N).map { ModInt(it) }.runningFold(ModInt(1), ModInt::times).toModIntArray()
        val ifs = Array(fs.size) { ModInt(1) / fs[it] }
        fun paths(a: Int, b: Int) = (fs[a + b] * ifs[b] * ifs[a])
        val ups = a.withIndex().fold(ModInt(0)) { acc, value -> acc + paths(value.value, value.index) }
        val rights = (a + -1).zipWithNext().withIndex().flatMap { (x, r) ->
            (r.second + 1..r.first).map { y -> paths(x, y) }
        }.fold(ModInt(0), ModInt::plus)
        println(((ups + rights - ModInt(1)).x))
    }
    System.err.println(tm.nanoseconds)
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }