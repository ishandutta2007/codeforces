import kotlin.math.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n, m, k) = readInts()
//    var n = 200000
//    var m = 100000
//    var k = 1000000000
    var arr = readInts().sorted().toIntArray()
//    var arr = IntArray(n) {it}
    var pref = LongArray(n + 1)
    for (i in 0 until n) {
        pref[i + 1] = pref[i] + arr[i]
    }
    var ans = Long.MAX_VALUE
    for (i in 0 until n - m + 1) {
        var l = i
        var r = i + (m + 1) / 2
//        System.err.println(l.toString() + " " + r.toString())
        while (r - l > 1) {
            val mid = (l + r) / 2
            if ((mid.toLong() - i) * arr[mid] - (pref[mid] - pref[i]) <= k) {
                l = mid
            } else {
                r = mid
            }
        }
//        System.err.println(i.toString() + " " + l.toString())
        val on_left = (l - i + 1)
        val on_right = m - on_left
        var pos = arr[l].toLong()
        if (on_left < on_right) {
            pos += (k - ((l - i).toLong() * arr[l] - (pref[l] - pref[i]))) / on_left
            pos = min(pos, (arr[i + m / 2] + arr[i + (m - 1) / 2]).toLong() / 2)
        }
//        System.err.println(i.toString() + " " + pos.toString() + " " + arr[l].toString())
//        System.err.println((l - i  + 1).toString() + " " + (i + m - l - 1).toString())
        ans = min(ans, (l - i + 1).toLong() * pos - (pref[l + 1] - pref[i]) + (pref[i + m] - pref[l + 1]) - (i + m - l - 1).toLong() * pos)
    }
    println(ans)
}