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
        var (n, k) = Array(2) { getInt() }
        var a = getInput()

        var rem = 0
        for (i in a)
            if (i == '1')
                rem++

        var taken = MutableList<Boolean>(n) { false }
        var nxt = MutableList(n) { (it + 1) % n }
        var lst = MutableList(n) { (it + n - 1) % n }

        var now = 0
        var eat = 0
        while (rem > 0) {
            taken[now] = true
            eat++
            if (a[now] == '1') rem--

            nxt[lst[now]] = nxt[now]
            lst[nxt[now]] = lst[now]

            for (i in 0 until k)
                now = nxt[now]
        }

        println(eat)
    }
}