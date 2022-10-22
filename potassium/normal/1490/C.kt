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
    var cubes = TreeSet<Long>()
    for (i in 1 .. 10000)
        cubes.add(1L * i * i * i)

    var t = getInt()
    while (t-- > 0) {
        var x = getLong()

        var found = false
        for (i in cubes)
            if (cubes.contains(x - i)) {
                found = true
                break
            }

        println(if (found) "YES" else "NO")
    }
}