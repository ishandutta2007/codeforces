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

var n = 0
var k = 0
var next = Array(1){0}
var prev = Array(1){0}

fun eat(cur : Int) {
    next[prev[cur]] = next[cur]
    prev[next[cur]] = prev[cur]
}

fun solve(sc : FastScanner) {
    var n = sc.nextInt()
    var k = sc.nextInt()
    next = Array(n){0}
    prev = Array(n){0}
    var s = sc.next().toString()
    var num = 0
    for (i in 0 until n) {
        if (s[i] == '1') num++
    }
    for (i in 0 until n) {
        next[i] = (i + 1) % n
        prev[i] = (i + n - 1) % n
    }
    var cur = 0
    var res = 0
    while (num > 0) {
//        println(cur)
        eat(cur)
        if (s[cur] == '1') num--
        res++
        if (num == 0) break
        for (i in 1..k) cur = next[cur]
    }
//    println("here")
    println(res)
}

fun main() {
    val sc = FastScanner(System.`in`)
    var tc = sc.nextInt()
    for (i in 0 until tc)
        solve(sc)
}