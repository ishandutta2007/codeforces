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
    var q = getInt()

    var nodes = MutableList<Array<Int>>(q + 1) { arrayOf(0, 0) }
    nodes[0] = arrayOf(getInt(), getInt())

    val MAXJ = 20
    var jump = MutableList<MutableList<Int>>(MAXJ) { MutableList<Int>(q + 1) { -1 } }

    fun find(u : Int) : Int {
        var ans = u
        for (i in MAXJ - 1 downTo 0)
            if (jump[i][ans] != -1 && nodes[jump[i][ans]][0] > 0)
                ans = jump[i][ans]

        return ans
    }

    for (qry in 1 .. q) {
        var cmd = getInt()
        if (cmd == 1) {
            jump[0][qry] = getInt()
            for (i in 1 until MAXJ)
                if (jump[i - 1][qry] != -1)
                    jump[i][qry] = jump[i - 1][jump[i - 1][qry]]

            nodes[qry] = arrayOf(getInt(), getInt())
        }
        else if (cmd == 2) {
            var (u, w) = arrayOf(getInt(), getInt())
            var ans = 0L
            var cnt = 0
            while (nodes[u][0] > 0 && w > 0) {
                var v = find(u)
                var take = minOf(w, nodes[v][0])
                w -= take
                nodes[v][0] -= take
                cnt += take

                ans += 1L * take * nodes[v][1]
            }

            println("$cnt $ans")
        }
        else myAssert(false)
    }
}