import kotlin.math.max
import kotlin.math.min

private fun solve(test: Int) {
    val (rows, cols) = readInts()
    val s = readLn()
    var minCol = 0
    var minRow = 0
    var maxCol = 0
    var maxRow = 0
    val dCol = listOf(1, 0, -1, 0).toIntArray()
    val dRow = listOf(0, 1, 0, -1).toIntArray()
    val dirs = "RDLU"
    var curCol = 0
    var curRow = 0
    var lastStartCol = 0
    var lastStartRow = 0
    for (c in s) {
        val dir = dirs.indexOf(c)
        curCol += dCol[dir]
        curRow += dRow[dir]
        minCol = min(minCol, curCol)
        minRow = min(minRow, curRow)
        maxCol = max(maxCol, curCol)
        maxRow = max(maxRow, curRow)
        if (!check(minCol, minRow, maxCol, maxRow, rows, cols)) {
            break
        } else {
            lastStartCol = -minCol
            lastStartRow = -minRow
        }
    }
    println("${lastStartRow + 1} ${lastStartCol + 1}")
}

fun check(minCol: Int, minRow: Int, maxCol: Int, maxRow: Int, rows: Int, cols: Int): Boolean {
    if (maxCol - minCol + 1 > cols) return false
    if (maxRow - minRow + 1 > rows) return false
    return true
}

fun main() {
    val t = readInt()
    repeat(t) { solve(it) }
}


private fun readInts() = readWords().map { it.toInt() }
private fun readLongs() = readWords().map { it.toLong() }
private fun readWords() = readLn().split(" ")
private fun readInt() = readLn().toInt()
private fun readLong() = readLn().toLong()
private fun readLn() = readLine()!!