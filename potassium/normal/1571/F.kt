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
    var (n,m) = Array(2) { getInt() }
    var k = Array<Int>(n) { 0 }
    var t = Array<Int>(n) { 0 }
    for (i in 0 until n) {
        k[i] = getInt()
        t[i] = getInt()
    }

    var total = k.sum()
    if (total > m) {
        println(-1)
        return
    }

    var dp = Array(m + 1) { 0 }
    var use = Array(m + 1) { -1 }
    dp[0] = 1

    for (i in 0 until n)
        if (t[i] == 2)
            for (j in m downTo k[i])
                if (dp[j] == 0 && dp[j - k[i]] == 1) {
                    dp[j] = 1
                    use[j] = i
                }

    var total2 = 0
    for (i in 0 until n)
        if (t[i] == 2)
            total2 += k[i]

    var take = total2 / 2
    while (dp[take] == 0) take--

    var s = Array(2) { mutableListOf<Int>() }
    run {
        var h = take
        while (h > 0) {
            s[1].add(use[h])
            h -= k[use[h]]
        }

        for (i in 0 until n)
            if (t[i] == 2 && !s[1].contains(i))
                s[0].add(i)
    }

    var startp = 0
    if (take * 2 == total2)
        startp = total2
    else
        startp = (total2 - take - 1) * 2 + 1

    var remSpace = m - startp
    if (remSpace < total - total2) {
        println(-1)
        return
    }

    var ans = Array(n) { 0 }

    var now = 0
    for (i in s[0]) {
        ans[i] = now
        now += k[i] * 2
    }

    now = 1
    for (i in s[1]) {
        ans[i] = now
        now += k[i] * 2
    }

    now = startp
    for (i in 0 until n)
        if (t[i] == 1) {
            ans[i] = now
            now += k[i]
        }

    println(ans.map { it + 1 }.joinToString(" "))
}