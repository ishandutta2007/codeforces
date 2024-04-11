import java.lang.Math.abs


fun main() {
    val n = readInt()
    val c = readInts()
    data class query(val l:Int, val r:Int, val id:Int)
    val q = readInt()
    val queries = List(q) { index -> val (l, r) = readInts(); query(l - 1, r - 1, index) }.groupBy {  it.r }
    val answers = MutableList<Long>(q) { 0 }
    data class item(val value: Int, val position: Int, val tot_sum:Long)

    val stack = mutableListOf(item(Int.MAX_VALUE, -1, 0))

    for (i in 0 until n) {
        var position = i
        while (stack.last().value <= c[i]) {
            position = stack.last().position
            stack.removeAt(stack.size - 1)
        }
        stack.add(item(c[i], position, stack.last().tot_sum + c[i] * 1L * (i - position + 1)))

        for ((l, _, qid) in queries.getOrDefault(i, emptyList())) {
            val id = (-stack.binarySearch { if (it.position < l) -1 else 1 } - 1)
            answers[qid] = stack.last().tot_sum - stack[id - 1].tot_sum +
                    ((stack.getOrNull(id)?.position ?: (i+1)) - l) * 1L * stack[id - 1].value
        }
    }

    println(answers.joinToString(" "))
}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }