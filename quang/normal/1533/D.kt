import java.io.*
import java.util.*
import kotlin.collections.HashSet
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
    var m = sc.nextInt()
    var s = HashMap<String, Int>()
    for (i in 0 until n) {
        var now = sc.next().toString()
        var cur = s.getOrDefault(now, 0)
        s[now] = cur + 1
    }
    var q = sc.nextInt()
    for (it in 0 until q) {
        var t = sc.next().toString()
        var has = HashSet<String>()
        var res = 0
        for (i in t.indices) {
            var now = ""
            if (i > 0) now += t.substring(0, i)
            if (i + 1 < t.length) now += t.substring(i + 1)
            if (has.contains(now)) continue
            has.add(now)
            res += s.getOrDefault(now, 0)
        }
        println(res)
    }
}

fun main() {
    val sc = FastScanner(System.`in`)
    var tc = 1
    for (i in 0 until tc)
        solve(sc)
}