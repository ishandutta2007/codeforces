import kotlin.comparisons.*;
fun main(args: Array<String>) {
    val t = readLine()!!.toInt()
    for (cs in 1..t) {
        val (n, m, p) = readLine()!!.split(' ').map(String::toInt)
        var can = false
        for (i in (1..m)) {
            if (!can && p % i == 0) {
                val j = p / i
                if (j <= n) {
                    can = true
                }
            }
        }
        if (can) {
            println("Yes")
        } else {
            println("No")
        }
    }
}