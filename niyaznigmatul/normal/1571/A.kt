fun main() {
    val n = readInt()
    repeat(n) {
        val s = readLn()
        val hasLess = s.contains("<")
        val hasGreater = s.contains(">")
        println(when {
            hasLess && hasGreater -> "?"
            hasLess -> "<"
            hasGreater -> ">"
            else -> "="
        })
    }
}

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!