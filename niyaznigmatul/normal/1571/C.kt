class ProblemC {
    class Pair(val first: String, val second: String, val rhyme: Boolean)

    private fun commonSuffix(x: String, y: String): Int {
        var count = 0
        while (count < x.length && count < y.length && x[x.length - count - 1] == y[y.length - count - 1]) {
            count++
        }
        return count
    }

    fun solve(test: Int) {
        val n = readInt()
        val pairs = Array(n) {
            val (f, s, r) = readWords()
            Pair(f, s, r == "1")
        }
        val maxNoRhyme = pairs
            .filter { !it.rhyme }
            .maxOfOrNull { commonSuffix(it.first, it.second) } ?: -1
        val minRhyme = pairs
            .filter { it.rhyme }
            .minOfOrNull { commonSuffix(it.first, it.second) } ?: Int.MAX_VALUE
        if (minRhyme <= maxNoRhyme) {
            println(0)
        } else {
            println(minRhyme - maxNoRhyme)
            println((maxNoRhyme + 1..minRhyme).joinToString(" "))
        }
    }
}

fun main(args: Array<String>) {
    val t = readInt()
    repeat(t) {
        ProblemC().solve(it)
    }
}

private fun readInts() = readWords().map { it.toInt() }

private fun readWords() = readLn().split(" ")

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!