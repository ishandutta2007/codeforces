private class Competition(val k: Int, val t: Int) {
    var answer: Int = -1
}

fun main() {
    val (n, m) = readInts()
    var start = 1
    val competitions = Array(n) {
        val (k, t) = readInts()
        Competition(k, t)
    }
    if (competitions.sumOf { it.k } > m) {
        println(-1)
        return
    }
    competitions.filter { it.t == 1 }.forEach {
        it.answer = start
        start += it.k
    }
    val otherCompetitions = competitions.filter { it.t == 2 }
    val left = m - start + 1
    val twoSets = splitIntoTwoSets(otherCompetitions, left)
    if (twoSets == null) {
        println(-1)
    } else {
        var startFirst = start + 1
        var startSecond = start
        for (x in twoSets.second) {
            x.answer = startSecond
            startSecond += 2 * x.k
        }
        for (x in twoSets.first) {
            x.answer = startFirst
            startFirst += 2 * x.k
        }
        println(competitions.map { it.answer }.joinToString(" "))
    }
}

private fun splitIntoTwoSets(comps: List<Competition>, days: Int): Pair<List<Competition>, List<Competition>>? {
    val sumAll = comps.sumOf { it.k }
    val n = comps.size
    val upTo = sumAll / 2 + 1
    val knapsack = Array(n + 1) { BooleanArray(upTo) }
    knapsack[0][0] = true
    for ((i, x) in comps.withIndex()) {
        for (j in 0 until upTo) {
            knapsack[i + 1][j] = knapsack[i][j]
            if (j >= x.k) {
                knapsack[i + 1][j] = knapsack[i + 1][j] || knapsack[i][j - x.k]
            }
        }
    }
    for (j in 0 until upTo) {
        if ((sumAll - j) * 2 - 1 > days) continue
        if (knapsack[n][j]) {
            var currentSize = j
            val firstList = mutableListOf<Competition>()
            val secondList = mutableListOf<Competition>()
            for ((i, x) in comps.withIndex().reversed()) {
                if (knapsack[i + 1][currentSize] == knapsack[i][currentSize]) {
                    secondList.add(x)
                } else {
                    firstList.add(x)
                    currentSize -= x.k
                }
            }
//            println(j)
//            println(firstList.map { "(${it.k}, ${it.t})" }.joinToString(", "))
//            println(secondList.map { "(${it.k}, ${it.t})" }.joinToString(", "))
            return Pair(firstList, secondList)
        }
    }
    return null
}

private fun readInts() = readWords().map { it.toInt() }

private fun readWords() = readLn().split(" ")

private fun readInt() = readLn().toInt()

private fun readLn() = readLine()!!