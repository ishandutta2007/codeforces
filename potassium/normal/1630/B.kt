import java.lang.AssertionError
import java.lang.StringBuilder
import java.util.*
import kotlin.math.*

val readQueue = ArrayDeque<String>()
fun getInput(): String {
    if (readQueue.isEmpty()) readLine()!!.split(' ', '\n').let{ readQueue.addAll(it) }
    return readQueue.pop()
}

fun getInt() = getInput().toInt()
fun getLong() = getInput().toLong()
fun getString() = getInput()

const val MOD107 = 1000000007L
const val MOD998 = 998244353L
fun myAssert(b : Boolean) {
    if (!b) throw AssertionError()
}

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var (n,k) = Array(2) { getInt() }
        var a = Array(n) { getInt() }

        var cnt = Array(n + 1) { 0 }
        for (i in a)
            cnt[i]++

        var (ansl, ansr) = arrayOf(1, n)
        run {
            var l = 1
            var sum = -n
            for (r in 1 .. n) {
                sum += 2 * cnt[r]
                while (sum - 2 * cnt[l] >= k) {
                    sum -= 2 * cnt[l]
                    l++
                }
                if (sum >= k && r - l < ansr - ansl) {
                    ansl = l
                    ansr = r
                }
            }
        }

        var itv = arrayListOf<Array<Int>>()
        var curL = 0
        var ps = 0
        for (i in 0 until n) {
            ps += if (a[i] in ansl .. ansr) +1 else -1
            if (ps == +1) {
                itv.add(arrayOf(curL + 1, i + 1))
                curL = i + 1
                ps = 0
            }
        }

        myAssert(itv.size >= k)
        itv[k - 1][1] = n
        println("$ansl $ansr\n" + (0 until k).map { itv[it].joinToString(" ") }.joinToString("\n"))
    }
}