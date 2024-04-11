import java.lang.AssertionError
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
    var a = readLine()!!.split(" ").map{ it.toLong() }

    var ans = 0L
    for (mix in 0 until 3) {
        var sum = mix.toLong()
        var poss = true
        for (i in a)
            if (i < mix)
                poss = false
            else
                sum += (i - mix) / 3

        if (poss)
            ans = Math.max(ans, sum)
    }

    println(ans)
}