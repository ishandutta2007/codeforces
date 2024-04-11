import java.io.BufferedReader
import java.io.InputStreamReader
import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of ints

private val br = BufferedReader(InputStreamReader(System.`in`))

private fun nextInt(): Int {
    var c = br.read()
    while (c <= 32) c = br.read()
    val neg = c == '-'.toInt()
    if (neg) c = br.read()
    var ans = 0
    while (c > 32) {
        ans = ans * 10 + c - '0'.toInt()
        c = br.read()
    }
    return when {
        neg -> -ans
        else -> ans
    }
}

fun main(args: Array<String>) {
    val n = nextInt()
    val m = nextInt()
    val k = nextInt()
    val a = IntArray(n) { nextInt() }
    val ans = solveFast(a, m, n, k)
    println(ans)
}

private fun solveFast(a: IntArray, m: Int, n: Int, k: Int): Long {
    val rng = Random(System.nanoTime())
    for (i in 0 until a.size) {
        val j = rng.nextInt(i + 1)
        val t = a[j]
        a[j] = a[i]
        a[i] = t
    }
    a.sort()
    val b = LongArray(n) { a[it].toLong() }
    for (i in 1 until b.size) {
        b[i] += b[i - 1]
    }
    var ans = Long.MAX_VALUE
    if (m == 1) {
        ans = 0
    } else {
        for (i in 0 until n) {
            if (i + m > n) break
            val sleft = i
            val sright = i + m - 1
            val smid = (sleft + sright) shr 1
            var left = sleft
            var right = smid + 1
            while (left < right - 1) {
                val mid = (left + right) shr 1
                val countLeft = mid - (sleft - 1)
                val sumLeft = b[mid] - (if (sleft == 0) 0L else b[sleft - 1])
                if (countLeft.toLong() * a[mid] - sumLeft > k) {
                    right = mid
                } else {
                    left = mid
                }
            }
            val mid = left
            val countLeft = mid - (sleft - 1)
            val sumLeft = b[mid] - (if (sleft == 0) 0L else b[sleft - 1])
            val stillHave = Math.min((k - (countLeft.toLong() * a[mid] - sumLeft)) / countLeft + a[mid], a[smid].toLong())
//            val stillHave = a[mid]
            val countRight = sright - mid
            val sumRight = b[sright] - b[mid]
            ans = Math.min(ans, (countLeft.toLong() * stillHave - sumLeft) + (sumRight - countRight.toLong() * stillHave))
        }
    }
    return ans
}