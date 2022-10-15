import kotlin.math.min

fun solve(test: Int) {
    val n = readInt()
    val (a, va) = readInts()
    val (c, vc) = readInts()
    val b = readInt()
    println(min(vc, va + (b - a)))
}

fun main() {
    val t = readInt()
    repeat(t) {
        solve(it)
    }
}

private fun readInts() = readLn().split(" ").map { it.toInt() }

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!