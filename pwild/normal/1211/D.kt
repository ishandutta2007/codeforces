import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n,a,b,k) = readInts()
    val m = 1000005
    var cnt = Array<Int>(m) { 0 }
    for (x in readInts()) {
        cnt[x]++
    }

    val rng = if (a > b) (0 until m) else (m-1 downTo 0)
    var res = 0
    for (i in rng) {
        if (i*1L*k >= m) continue
        val take = min(cnt[i]/a, cnt[i*k]/b)
        res += take
        cnt[i] -= take*a
        cnt[i*k] -= take*b
    }
    println(res)

}