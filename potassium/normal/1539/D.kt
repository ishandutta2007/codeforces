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
    val a = MutableList<Array<Long>>(n) { arrayOf(getLong(), getLong()) }
    a.sortWith { x, y -> x[1].compareTo(y[1]) }

    val dq = ArrayDeque<Array<Long>>()
    for (i in a)
        dq.addLast(i)

    var ans = 0L
    var cnt = 0L
    while (!dq.isEmpty()) {
        if (dq.first[1] <= cnt) {
            ans += dq.first[0]
            cnt += dq.first[0]
            dq.removeFirst()
        }
        else {
            var need = dq.first[1] - cnt
            var take = minOf(need, dq.last[0])

            dq.last[0] -= take
            ans += 2 * take
            cnt += take
            if (dq.last[0] == 0L)
                dq.removeLast()
        }
    }

    println(ans)
}