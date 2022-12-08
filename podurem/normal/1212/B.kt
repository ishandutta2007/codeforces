private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val s = readLn()
    val map = HashMap<String, Int>()
    for (i in 0 until s.length-1) {
        val sub = s[i].toString() + s[i + 1].toString()
        map[sub] = map.getOrDefault(sub, 0) + 1
    }
    println(map.maxBy { it.value }!!.key)
}