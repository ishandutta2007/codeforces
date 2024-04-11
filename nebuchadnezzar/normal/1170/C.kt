private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var t = readInt()
    for (q in 0 until t) {
        var s = readLn()
        var t = readLn()
        var cnt = 0
        var ok = true
        for (i in 0 until t.length) {
            if (cnt == s.length) {
                ok = false
                break
            }
            if (t[i] == '-') {
                if (s[cnt] == '+') {
                    ok = false
                    break
                }
                cnt++
            } else {
                if (s[cnt] == '+') {
                    cnt++
                } else {
                    if (cnt + 1 == s.length || s[cnt + 1] == '+') {
                        ok = false
                        break
                    }
                    cnt += 2
                }
            }
        }

        if (cnt < s.length) {
            ok = false
        }

        if (ok) {
            println("YES")
        } else {
            println("NO")
        }
    }
}