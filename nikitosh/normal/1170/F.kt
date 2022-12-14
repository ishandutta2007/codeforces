import java.io.*
import java.util.*

fun main() {
    val strs = readLine()!!.split(" ")
    val n = Integer.parseInt(strs[0])
    val m = Integer.parseInt(strs[1])
    val k = Integer.parseInt(strs[2])
    val a = readLine()!!.split(" ").map { it.toInt() }.sorted().toIntArray()
    val sums = LongArray(n + 1, {it -> 0})
    for (i in 1..n)
        sums[i] = sums[i - 1] + a[i - 1]
    val bb = LongArray(n, {it -> 0})
    for (i in 0..(n - 1)) {
        bb[i] = a[i].toLong() * i - sums[i]
    }
    var ans = 1000000000000000000
    for (i in 0..(n - m)) {
        val ind = i + (m - 1) / 2
        val pp = k - sums[i]
        if (bb[ind] - a[ind].toLong() * i <= pp) {
            val mm = ind
            ans = minOf(ans, a[mm].toLong() * (mm - i).toLong() - (sums[mm] - sums[i]) + (sums[i + m] - sums[mm + 1]) - a[mm].toLong() * (i + m - mm - 1).toLong()); 
            continue        
        }
        var l = i
        var r = i + m
        val cc = 4000
        if (m >= cc + 1) {
            if (bb[l + cc] - a[l + cc].toLong() * i > pp) {
                r = l + cc
            }
        }
        while (r - l > 1) {
            val mm = (l + r) / 2
            if (bb[mm] - a[mm].toLong() * i <= pp)
                l = mm
            else
                r = mm
        }
        val kk = a[l].toLong() * (l - i).toLong() - (sums[l] - sums[i])
        val value = a[l] + (k - kk) / (l - i + 1)
        val rem = (l - i + 1).toLong()
        ans = minOf(ans, value * rem - (sums[l + 1] - sums[i]) + (sums[i + m] - sums[l + 1]) - value.toLong() * (m - rem).toLong()); 
    }
    val log = BufferedWriter(OutputStreamWriter(System.`out`));
    log.write(ans.toString() + "\n")
    log.flush();
}