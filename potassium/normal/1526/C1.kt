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
    var a = MutableList(n) { getInt() }

    var ans = 0
    var health = 0L
    var pq = PriorityQueue<Int>()

    for (i in a) {
        if (health + i >= 0) {
            health += i
            pq.add(i)
            ans++
        }
        else if (!pq.isEmpty() && pq.peek() < i) {
            health -= pq.poll()
            health += i
            pq.add(i)
        }
    }

    println(ans)
}