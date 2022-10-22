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
    var m = getInt()
    var a = MutableList(m) { getInt() }

    var cnt = 0
    for (i in a)
        if (i == -1) cnt++

    var ans = Array(cnt) { mutableListOf<Int>() }
    var nxt = Array(cnt) { (it + 1) % cnt }
    var lst = Array(cnt) { (it + cnt - 1) % cnt }

    var now = 0
    for (i in a) {
        if (i == -1) {
            nxt[lst[now]] = nxt[now]
            lst[nxt[now]] = lst[now]
        }
        else {
            ans[now].add(i)
        }
        now = nxt[now]
    }

    var ansStr = StringBuilder("$cnt\n")
    for (i in ans)
        ansStr.append("${i.size} ${i.joinToString(" ")}\n")

    println(ansStr)
}