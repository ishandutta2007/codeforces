import java.util.*

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main(args: Array<String>) {
    val n = readInt()
    for (i in 1..n) {
        val s = readLn()
        val t = readLn()
        var cur = 0
        var ok = true
        for (x in t) {
            if (cur >= s.length) {
                ok = false
                break
            }
            if (x == '-') {
                if (s[cur] == '-') {
                    cur++;
                    continue
                }
                ok = false;
                break
            } else {
                if (s[cur] == '+') {
                    cur++
                    continue
                }
                if (cur + 1 >= s.length || s[cur + 1] != '-') {
                    ok = false
                    break
                }
                cur += 2
                continue
            }
        }
        if (cur != s.length) ok = false
        println(if (ok) "YES" else "NO")
    }
}