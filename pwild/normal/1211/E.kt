private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts()
    val m = 200005

    var kmin = 1
    var kmax = n+2
    while (kmax-kmin > 1) {
        val k = (kmin+kmax)/2
        val red = ArrayList<Int>()
        val green = ArrayList<Int>()
        val count = Array<Int>(m) { 0 }
        for (x in a) {
            if (x < k) {
                if (count[x] == 0) red.add(x)
                else green.add(x)
            }
            count[x]++
        }
        if (red.toArray() contentEquals green.toArray() && red.size == k-1) {
            kmin = k
        } else {
            kmax = k
        }
    }

    val res = Array<Char>(n) { 'B' }
    val count = Array<Int>(m) { 0 }

    for (i in 0 until n) {
        if (a[i] >= kmin) continue
        res[i] = if (count[a[i]] == 0) 'G' else 'R'
        count[a[i]]++
    }
    println(res.joinToString(""))
}