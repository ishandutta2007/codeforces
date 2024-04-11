import java.io.*
import java.lang.Integer.max
import java.util.*

class FastScanner {
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

fun solve(sc : FastScanner) {
    var n = sc.nextInt()
    var a = Array(n){0}
    for (i in a.indices) {
        a[i] = sc.nextInt()
    }
    var b = Array(n + 1){0}
    for (i in b.indices) {
        b[i] = sc.nextInt()
    }
    a.sort()
    b.sort()
    var prefSum = Array(n){ (-2e9 - 10).toInt() }
    var suffSum = Array(n){ (-2e9 - 10).toInt() }
    for (i in a.indices) {
        if (i > 0) prefSum[i] = prefSum[i - 1]
        prefSum[i] = max(prefSum[i], b[i] - a[i])
    }
    for (i in a.indices.reversed()) {
        if (i + 1 < a.size) suffSum[i] = suffSum[i + 1]
        suffSum[i] = max(suffSum[i], b[i + 1] - a[i])
    }

    var m = sc.nextInt()
    for (it in 0 until m) {
        var c = sc.nextInt()
        var low = -1
        var high = a.size
        while (high - low > 1) {
            var mid = (low + high) / 2
            if (a[mid] < c) low = mid
            else high = mid
        }
        var res = b[high] - c
        if (high > 0) res = max(res, prefSum[high - 1])
        if (high < suffSum.size) res = max(res, suffSum[high])
        print("${res} ")
    }
    println("")
}

fun main() {
    val sc = FastScanner(System.`in`)
    var tc = 1
    for (i in 0 until tc)
        solve(sc)
}