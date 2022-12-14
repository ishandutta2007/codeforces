import kotlin.math.min
 
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readDouble() = readLn().toDouble() // single double
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs
private fun readDoubles() = readStrings().map { it.toDouble() } // list of doubles
 
fun main(args: Array<String>) {
    var t = readInt()
    for (i in 0 until t) {
        var (n, k) = readInts()
        var s = readLn()
        var bal = 0
        var cnt1 = 0
        var cnt2 = 0
        for (i in 0 until n) {
            if (s[i] == '(')
                bal++
            else {
                bal--
                if (bal > 0)
                    cnt1++
                else
                    cnt2++
            }
        }
        println(cnt2 + min(k, cnt1))
    }
}