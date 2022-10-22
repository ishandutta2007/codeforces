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
    var t = getInt()
    while (t-- > 0) {
        var n = getInt()
        var k = getInt()
        var s = getString()

        var bal = 0
        var quo = 0
        var zero = 0
        for (i in s) {
            if (i == '(') {
                bal++
            }
            else {
                if (--bal > 0)
                    quo++
                else
                    zero++
            }
        }

        var ans = zero + Math.min(k, quo)
        println(ans)
    }
}