
private val cacheA = mutableMapOf<Int, Boolean>()
private val cacheB = mutableMapOf<Int, Boolean>()
private fun solveA(a:Int,b:Int, cur:Int) : Boolean = cacheA.getOrPut((a * 100 + b) * 2 + cur) {
    when {
        a == 0 && b == 0 -> cur == 0
        a == 0 -> solveB(a, b - 1, cur xor 1)
        b == 0 -> solveB(a - 1, b, cur)
        else -> solveB(a, b - 1, cur xor 1) || solveB(a - 1, b, cur)
    }
}
private fun solveB(a:Int,b:Int, cur:Int) : Boolean = cacheB.getOrPut((a * 100 + b) * 2 + cur) {
    when {
        a == 0 && b == 0 -> cur == 0
        a == 0 -> solveA(a, b - 1, cur)
        b == 0 -> solveA(a - 1, b, cur)
        else -> solveA(a, b - 1, cur) && solveA(a - 1, b, cur)
    }
}

private fun solve() : Boolean {
    readInt()
    val a = readInts()
    return solveA(a.count { it % 2 == 0 }, a.count { it % 2 != 0 }, 0)
}

fun main() {
    repeat(readInt()) {
        println(if (solve()) "Alice" else "Bob")
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }