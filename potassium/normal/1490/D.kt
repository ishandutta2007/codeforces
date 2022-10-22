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
fun binpow(b : Long, p : Long, mod : Long) : Long {
    var pw = p
    var cur = b
    var ans = 1L
    while (pw > 0) {
        if ((pw and 1) > 0)
            ans = (ans * cur) % mod

        cur = (cur * cur) % mod
        pw = pw shr 1
    }
    return ans
}

fun main() {
    var t = getInt()
    while (t-- > 0) {
        var n = getInt()
        var a = MutableList(n) { getInt() }

        var ans = MutableList(n) { 0 }
        fun solve(l : Int, r : Int, d : Int) {
            if (l > r) return

            var maxi = l
            for (i in l .. r)
                if (a[i] > a[maxi]) maxi = i

            ans[maxi] = d
            solve(l, maxi - 1, d + 1)
            solve(maxi + 1, r, d + 1)
        }
        solve(0, n - 1, 0)

        println(ans.joinToString(" "))
    }
}