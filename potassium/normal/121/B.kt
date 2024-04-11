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
    var (n,k) = arrayOf(getInt(), getInt())
    var a = StringBuilder(getString())

    var idx = 0
    var t = k
    while (t > 0) {
        if (idx % 2 == 0) {
            while (idx + 3 <= n && a.substring(idx, idx + 3).equals("447")) {
                t %= 2
                idx++
                break
            }

            if (t == 0)
                break
        }

        while (idx + 2 <= n && !a.substring(idx, idx + 2).equals("47"))
            idx++

        if (idx + 2 > n)
            break

        myAssert(a.substring(idx, idx + 2).equals("47"))
        if (idx % 2 == 0)
            a[idx + 1] = '4'
        else {
            a[idx] = '7'
            idx--
        }

        t--
    }

    println(a)
}