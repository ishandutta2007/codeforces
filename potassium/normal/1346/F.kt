import java.lang.*
import java.util.*
import java.math.*
import kotlin.math.*

fun readLn() = readLine()!!
fun readInt() = readLn().toInt()
fun readInts() = readLn().split(" ").map{ it.toInt() }
fun readLong() = readLn().toLong()
fun readLongs() = readLn().split(" ").map{ it.toLong() }


fun sol(vec : LongArray, total : Long) : Long {
    var median = (total + 1) / 2
    var total = 0L

    var pos = -1

    for (i in vec.indices) {
        total += vec[i]
        if (total >= median) {
            pos = i
            break
        }
    }

    var ans = 0L
    for (i in vec.indices)
        ans += vec[i] * Math.abs(i - pos)

    return ans
}

fun solve(row : LongArray, col : LongArray, total : Long) : Long {
    return sol(row, total) + sol(col, total)
}

fun main() {
    var L1 = readInts()

    var n = L1[0]
    var m = L1[1]
    var q = L1[2]

    var total = 0L
    var row = LongArray(n)
    var col = LongArray(m)

    var board = arrayListOf<ArrayList<Long>>()

    for (i in 0 until n) {
        var tmp = readLongs()
        board.add( ArrayList<Long>() )
        for (j in 0 until m)
            board[i].add(tmp[j])
    }

    for (i in 0 until n)
        for (j in 0 until m) {
            row[i] += board[i][j]
            col[j] += board[i][j]
            total += board[i][j]
        }

    print(solve(row, col, total))

    for (i in 0 until q) {
        var L3 = readInts()

        var x = L3[0] - 1
        var y = L3[1] - 1
        var z = L3[2].toLong()

        total -= board[x][y]
        row[x] -= board[x][y]
        col[y] -= board[x][y]

        board[x][y] = z

        total += board[x][y]
        row[x] += board[x][y]
        col[y] += board[x][y]

        print(" ")
        print(solve(row, col, total))
    }

    println()
}