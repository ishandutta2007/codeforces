import java.io.*
import java.lang.Integer.max
import java.util.*
import kotlin.collections.ArrayList

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
    var s = sc.next().toString()
    var n = s.length
    var list = Array(2){ArrayList<Int>()}
    var pos = Array(2){Array(n){0} }
    for (i in s.indices) {
        var id = if (s[i] == '0') 0 else 1
        pos[0][i] = list[0].size
        pos[1][i] = list[1].size
        list[id].add(i)
    }

//    for (u in list[0]) print("$u ")
//    println("")
//    for (u in list[1]) print("$u ")
//    println("")

    for (i in 1..n) {
        var cur = 0
        var res = 0
        while (cur < n) {
            var cur0 = pos[0][cur]
            var cur1 = pos[1][cur]
//            println("cur $cur0 $cur1")
            var pos0 = if (cur0 + i >= list[0].size) n else list[0][cur0 + i]
            var pos1 = if (cur1 + i >= list[1].size) n else list[1][cur1 + i]
//            println("pos $pos0 $pos1")
            cur = max(pos0, pos1)
            res++
        }
        print("$res ")
    }
    println("")
}


fun main() {
    val sc = FastScanner(System.`in`)
    var tc = 1
    val begin = System.currentTimeMillis()
    for (i in 0 until tc)
        solve(sc)
    val end = System.currentTimeMillis()
//    println("Elapsed time in milliseconds: ${end-begin}")
}