import java.io.*
import java.util.*

fun main() {
    val bi = BufferedReader(InputStreamReader(System.`in`));
    val strs = bi.readLine().split(" ")
    val n = Integer.parseInt(strs[0])
    val m = Integer.parseInt(strs[1])
    val line = bi.readLine()
    val a = IntArray(n, {it -> 0})
    var it = 0
    for (numStr in line.split(" ")) {
        a[it] = Integer.parseInt(numStr)
        it += 1
    }
    val sums = IntArray(n + 1, {it -> 0})
    for (i in 1..n) {
        sums[i] = sums[i - 1] + a[i - 1]
    }
    val q = Integer.parseInt(bi.readLine())
    val log = BufferedWriter(OutputStreamWriter(System.`out`));
    repeat(q) {
        val strs = bi.readLine().split(" ")
        val k = Integer.parseInt(strs[0])
        var last = 0
        var it = 0
        for (i in 1..k+1) {
            var cur = m + 1
            if (i != k + 1)
                cur = Integer.parseInt(strs[i])
            val len = cur - last - 1
            var l = it
            var r = n + 1
            while (r - l > 1) {
                var m = (l + r) / 2
                if (sums[m] - sums[it] <= len)
                    l = m
                else
                    r = m
            }
            it = l
            last = cur
        }
        if (it == n)
            log.write("YES")
        else
            log.write("NO")
        log.write("\n");
    }
    log.flush();
}