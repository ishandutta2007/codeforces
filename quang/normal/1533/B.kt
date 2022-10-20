import java.io.*
import java.util.*
import kotlin.math.max

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
    var f = false
    for (i in 0 until n) {
        a[i] = sc.nextInt()
    }
    for (i in 1..n - 1) {
        if ((a[i] - a[i - 1]) % 2 == 0) {
            f = true
            break
        }
    }
    if (f) println("YES")
    else println("NO")
}

fun main() {
    val sc = FastScanner(System.`in`)
    var tc = sc.nextInt()
    for (i in 0 until tc)
        solve(sc)
}