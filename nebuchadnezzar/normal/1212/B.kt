private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var n = readInt()
    var s = readLn()
    var cnt = HashMap<String, Int>()
    for (i in 0 until n - 1) {
//        cnt[s.substring(i, i + 2)]
        val cur = s.substring(i, i + 2)
        cnt.put(cur, cnt.getOrDefault(cur, 0) + 1)
    }
    var best = -1
    var mem = ""
    for (entry in cnt) {
        if (entry.value > best) {
            best = entry.value
            mem = entry.key
        }
    }
    println(mem)
}