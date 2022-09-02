fun main() {
    val n = readInt()
    val a = readInts()
    val have = BooleanArray(1001)
    val filtered = a.reversed().filter { val ret = !have[it]; have[it] = true; ret }.reversed()
    println(filtered.size)
    println(filtered.joinToString(" "))
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }