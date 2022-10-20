import java.io.*
import java.util.*
import kotlin.math.max

val INF = 1000000000

fun main() {
    val sc = FastScanner(System.`in`)
    var n = sc.nextInt()
    var k = sc.nextInt()
    var a = Array(n + 1){0}
    for (i in 1..n) a[i] = sc.nextInt()
    a.sort()
    var sum = Array(n + 1){0}
    for (i in 1..n) sum[i] = sum[i - 1] + a[i]

    var dp = Array(n + 1){Array(k + 1){-INF}}
    dp[0][0] = 0
    for (i in 1..n) {
        dp[i][0] = 0
        for (j in 1..k) {
            dp[i][j] = dp[i - 1][j]
            for (x in 1..j) {
                var last = i - x * 2
                var mid = i - x
                if (last >= 0) {
                    dp[i][j] = max(dp[i][j], dp[last][j - x] + sum[i] - 2 * sum[mid] + sum[last])
                }
            }
        }
    }
    println(dp[n][k])
}

internal class FastScanner {
    var br: BufferedReader? = null
    var st: StringTokenizer? = null

    constructor(f: File?) {
        try {
            br = BufferedReader(FileReader(f))
        } catch (e: FileNotFoundException) {
            e.printStackTrace()
        }
    }

    constructor(f: InputStream?) {
        br = BufferedReader(InputStreamReader(f))
    }

    operator fun next(): String? {
        while (st == null || !st!!.hasMoreTokens()) {
            var s: String? = null
            try {
                s = br!!.readLine()
            } catch (e: IOException) {
                e.printStackTrace()
            }
            if (s == null) return null
            st = StringTokenizer(s)
        }
        return st!!.nextToken()
    }

    fun hasMoreTokens(): Boolean {
        while (st == null || !st!!.hasMoreTokens()) {
            var s: String? = null
            try {
                s = br!!.readLine()
            } catch (e: IOException) {
                e.printStackTrace()
            }
            if (s == null) return false
            st = StringTokenizer(s)
        }
        return true
    }

    fun nextInt(): Int {
        return next()!!.toInt()
    }

    fun nextLong(): Long {
        return next()!!.toLong()
    }

    fun nextDouble(): Double {
        return next()!!.toDouble()
    }
}