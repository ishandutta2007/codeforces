import kotlin.math.max
import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var (n, a, b, k) = readInts()
    var arr = readInts()
    var cnt = HashMap<Int, Int>()
    for (i in 0 until n) {
        cnt.put(arr[i], cnt.getOrDefault(arr[i], 0) + 1)
    }
    var dst = arr.distinct()
    var ans = 0
    var used = HashSet<Int>()
    for (i in 0 until dst.size) {
        var tmp = dst[i]
        while (tmp % k == 0) {
            tmp /= k
        }
        if (used.contains(tmp)) {
            continue
        }
        used.add(tmp)
        var cur = tmp
        var carr = ArrayList<Int>()
        while (cur <= 1000000) {
            carr.add(cnt.getOrDefault(cur, 0))
//                System.err.print(carr.last().toString() + " ")
            cur *= k
        }
//            System.err.println()
        var d = IntArray(carr[0] + 1)
        for (j in 0 until carr.size - 1) {
            var next = IntArray(carr[j + 1] + 1)
            var pref_max = IntArray(carr[j] + 2)
            for (q in 0 until carr[j] + 1) {
                pref_max[q + 1] = max(pref_max[q], d[q])
            }
            for (q in 0 until min(carr[j] / a, carr[j + 1] / b) + 1) {
                next[b * q] = pref_max[carr[j] - q * a + 1] + q
            }
            d = next
        }
        var best = 0
        for (num in d) {
            best = max(best, num)
        }
        ans += best
    }
    println(ans)
}