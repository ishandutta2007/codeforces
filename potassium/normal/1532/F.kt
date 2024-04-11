import java.lang.AssertionError
import java.math.BigInteger
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
    var n = getInt()
    var s = MutableList<String>(2 * n - 2) { getInput() }

    var x = MutableList<String>(0) { "" }
    var y = MutableList<String>(0) { "" }
    for (i in s) {
        if (i.length == 1)
            x.add(i)
        if (i.length == n - 1)
            y.add(i)
    }

    myAssert(x.size == 2)
    myAssert(y.size == 2)

    fun go(str : String) : Boolean {
        var affix = MutableList<String>(0) { "" }
        for (i in 0 until n - 1) {
            affix.add(str.substring(0, i + 1))
            affix.add(str.substring(i + 1, n))
        }
        myAssert(affix.size == 2 * n - 2)
        return s.sorted() == affix.sorted()
    }

    for (mask in 0 until 4) {
        var now = x[(mask shr 1) and 1] + y[(mask) and 1]
        if (go(now)) {
            var pre = MutableList<Boolean>(n) { false }
            var suf = MutableList<Boolean>(n) { false }

            var ans = MutableList<Char>(n * 2 - 2) { '_' }
            for (i in s.indices) {
                var len = s[i].length
                if (!pre[len - 1] && now.substring(0, len) == s[i]) {
                    pre[len - 1] = true
                    ans[i] = 'P'
                }
                else if (!suf[n - len] && now.substring(n - len, n) == s[i]) {
                    suf[n - len] = true
                    ans[i] = 'S'
                }
                else myAssert(false)
            }

            println(ans.joinToString(""))
            return
        }
    }

    myAssert(false)
}