import kotlin.math.max

fun main(args: Array<String>) {
    val (n, m) = readInts()
    val firstCount = IntArray(n)
    val lastCount = IntArray(n)
    val bothCount = Array(n) { IntArray(n) }
    val (ourFirst, ourLast) = readInts().map { it - 1 }
    repeat(m - 1) {
        val (f, l) = readInts().map { it - 1 }
        bothCount[f][l]++
        firstCount[f]++
        lastCount[l]++
    }
    var answer = 1
    for (f in 0 until n) {
        for (l in 0 until n) {
            if (f == l || ourFirst == f || ourLast == l) continue
            val place = firstCount[f] + lastCount[l] - bothCount[f][l] + 1
            answer = max(answer, place)
        }
    }
    println(answer)
}

private fun readInts() = readWords().map { it.toInt() }

private fun readWords() = readLn().split(" ")

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!