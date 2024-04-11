import java.io.*
import java.util.*
import kotlin.math.max

fun main() {
//    val sc = Scanner(System.`in`)
    val sc = FastScanner(System.`in`)
    var n = sc.nextInt()
    var k = sc.nextInt()
    var x = sc.nextInt()
    var a = Array(n + 1){0}
    for (i in 1..n) a[i] = sc.nextInt()

    var low = -1L
    var high = 20000000000L
    while (high - low > 1) {
        var mid = (low + high) / 2

        var need = 0
        var cur = 1
        while (cur <= n) {
            var s = TreeSet<Pair<Int, Int>>(object: Comparator<Pair<Int, Int>>{
                override fun compare(p1: Pair<Int, Int>, p2: Pair<Int, Int>): Int {
                    if (p1.first != p2.first) return if (p1.first < p2.first) -1 else 1
                    if (p1.second != p2.second) return if (p1.second < p2.second) -1 else 1
                    return 0
                }
            })
            var curSum = 0L
            var curNum = 0
            while (cur <= n && curNum < x) {
                curNum++
                curSum += a[cur]
                s.add(Pair(a[cur], cur))
                cur++
            }
            while (cur <= n && curSum > mid) {
                var biggest = s.last()
                s.remove(biggest)
                var now = biggest.first
                curSum -= now

                curSum += a[cur]
                s.add(Pair(a[cur], cur))
                cur++
                need++
            }
            if (cur <= n) continue
            while (curSum > mid) {
                var biggest = s.last()
                s.remove(biggest)
                var now = biggest.first
                curSum -= now
                need++
            }
        }
//        println("$mid $need")
        if (need > k) low = mid
        else high = mid
    }
    println(high)
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