fun main() {
    val q = readInt()
    var lf = 0
    var rg = 0
    val ids = mutableMapOf<Int, Int>()
    ids[readStrings()[1].toInt()] = 0
    for (i in 2..q) {
        val (ty, value_) = readStrings()
        val value = value_.toInt()
        when (ty) {
            "L" -> ids[value] = --lf
            "R" -> ids[value] = ++rg
            "?" -> println(Math.min(ids[value]!! - lf, rg - ids[value]!!))
        }
    }
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }