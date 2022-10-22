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
    fun ask(a : Array<Int>) : Int {
        println("? ${a.joinToString(" ")}")
        return getInt()
    }

    val LOWER = (1 shl 7) - 1
    val UPPER = LOWER shl 7

    println("! ${ ( UPPER and ask(Array<Int>(100) { it + 1 }) ) or ( LOWER and ask(Array<Int>(100) { (it + 1) shl 7 })) }")
}