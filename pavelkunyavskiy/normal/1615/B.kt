private val lst = Array(20) { bit ->
    (0 until 200_100).filter { (it and (1 shl bit)) != 0 }.toIntArray()
}

fun IntArray.lowerBound(x: Int) = binarySearch(x).let {
    if (it >= 0) it else -it-1
}

private fun solve() {
    val (l, r_) = readInts()
    val r = r_ + 1
    println(r - l -
            lst.maxOf {
                it.lowerBound(r) - it.lowerBound(l)
            }
    )
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