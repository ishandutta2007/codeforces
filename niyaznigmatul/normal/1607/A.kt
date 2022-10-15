
private fun solve(test: Int) {
    val keyboard = readLn()
    val text = readLn()
    var ans = 0
    val pos = IntArray(26)
    for ((i, c) in keyboard.withIndex()) {
        pos[c.toInt() - 'a'.toInt()] = i
    }
    fun getPos(c: Char): Int {
        return pos[c.toInt() - 'a'.toInt()]
    }
    var last = getPos(text[0])
    for (c in text.substring(1)) {
        val cur = getPos(c)
        ans += Math.abs(cur - last)
        last = cur
    }
    println(ans)
}

fun main() {
    val t = readInt()
    repeat(t) { solve(it) }
}


private fun readInts() = readWords().map { it.toInt() }

private fun readWords() = readLn().split(" ")

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!