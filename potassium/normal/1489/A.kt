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
    var n = getInt()
    var a = MutableList(n) { getInt() }

    var ans = MutableList(0) { 0 }
    for (i in 0 until a.size) {
        var dup = false
        for (j in i + 1 until a.size) {
            if (a[i] == a[j]) {
                dup = true
                break
            }
        }

        if (!dup)
            ans.add(a[i])
    }

    println(ans.size)
    println(ans.joinToString(" "))
}