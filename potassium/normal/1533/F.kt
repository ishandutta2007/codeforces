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
    var s = getInput()
    val n = s.length

    var cnt = Array(2) { Array(n + 1) { 0 } }
    for (i in 1 .. n) {
        cnt[0][i] = cnt[0][i - 1]
        cnt[1][i] = cnt[1][i - 1]
        cnt[s[i - 1] - '0'][i]++
    }

    var ans = MutableList(n) { 1 }
    for (k in 1 .. n) {
        ans[k - 1] = 0
        var now = 0
        while (now != Integer.MAX_VALUE) {
            ans[k - 1]++
            if (cnt[0][n] - cnt[0][now] <= k || cnt[1][n] - cnt[1][now] <= k) break
            var l = now + 2 * k
            var r = n
            while (r > l) {
                var mid = (l + r + 1) shr 1
                if (cnt[0][mid] - cnt[0][now] <= k || cnt[1][mid] - cnt[1][now] <= k)
                    l = mid
                else
                    r = mid - 1
            }
            now = l
        }

        if (ans[k - 1] == 1)
            break
    }

    println(ans.joinToString(" "))
}