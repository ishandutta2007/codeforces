import java.lang.StringBuilder

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var (n, m) = readInts()
    var doors = readInts()
    var q = readInt()
    var pref = ArrayList<Int>()
    pref.add(0)
    for (w in doors) {
        pref.add(pref.last() + w)
    }
    var outp = StringBuilder()
    for (i in 0 until q) {
        var day = readInts()
        var cnt = 0
        var from = 0
        for (j in 0 until day[0] + 1) {
            var pos = m
            if (j < day[0]) {
                pos = day[j + 1] - 1
            }
            var l = cnt
            var r = n + 1
            while (r - l > 1) {
                var mid = (l + r) / 2
                if (pref[mid] - pref[cnt] <= pos - from) {
                    l = mid
                } else {
                    r = mid
                }
            }
            cnt = l
            from = pos + 1
        }
        if (cnt == n) {
            outp.append("YES\n")
        } else {
            outp.append("NO\n")
        }
    }
    print(outp.toString())
}