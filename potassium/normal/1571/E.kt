import java.lang.AssertionError
import java.lang.StringBuilder
import java.util.*

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
        var n = getInt()
        var s = getInput()
        var a = "000" + getInput()

        var has = false
        for (i in 0 until n) {
            if (a[i] != '1') continue
            if (i + 1 < n && a[i + 1] == '1') has = true
            if (i + 3 < n && a[i + 3] == '1') has = true
        }

        if (has) {
            println(-1)
            continue
        }

        var sb = StringBuilder(s)
        var ab = StringBuilder(a)
        var forced = false
        var ans = 0

        while (!sb.isEmpty()) {
            if (forced) {
                forced = ab.last() == '1'

                if (sb[sb.length - 1] != ')') ans++
                if (sb[sb.length - 2] != '(') ans++
                sb.setLength(sb.length - 2)
                ab.setLength(ab.length - 2)
                continue
            }

            if (ab.last() == '0') {
                sb.setLength(sb.length - 1)
                ab.setLength(ab.length - 1)
                continue
            }

            if (ab.length >= 3 && ab[ab.length - 3] == '1') {
                forced = true

                if (sb[sb.length - 1] != ')') ans++
                if (sb[sb.length - 2] != '(') ans++
                sb.setLength(sb.length - 2)
                ab.setLength(ab.length - 2)
                continue
            }

            var sub = sb.substring(sb.length - 4, sb.length)
            if (sub[0] != '(') ans++
            if (sub[3] != ')') ans++
            if (sub[1] == sub[2]) ans++
            sb.setLength(sb.length - 4)
            ab.setLength(ab.length - 4)
        }

        println(ans)
    }
}