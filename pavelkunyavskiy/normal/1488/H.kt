import java.text.FieldPosition

private val MOD = 998244353

private class Matrix(val x : Array<IntArray>) {

    operator fun times(other: Matrix) : Matrix {
        return Matrix(
            Array(4) { i ->
                IntArray(4) { j ->
                    var s = 0
                    for (k in 0..3) {
                        s = ((s + x[i][k] * 1L* other.x[k][j]) % MOD).toInt()
                    }
                    s
                }
            }
        )
    }
}

private fun genMatrix(f : (Int,Int)->Boolean) : Matrix {
    return Matrix(Array(4) { i -> IntArray(4) { j -> if (f(i, j)) 1 else 0}})
}

private fun unit() : Matrix {
    return genMatrix({i, j -> i == j})
}


fun main() {
    val (n, q) = readInts()
    val current = readInts().toMutableList()
    current.add(0)
    val lst = { var s = 1; while (s < n) s *= 2; s }()

    val tree = Array(2 * lst) { unit() }

    fun getMatrix(position: Int) : Matrix {
        if (current[position] == 0) {
            if (current[position + 1] == 0) {
                return genMatrix { i: Int, j: Int -> i >= j }
            } else {
                return genMatrix { i: Int, j: Int -> i > j }
            }
        } else {
            if (current[position + 1] == 0) {
                return genMatrix { i: Int, j: Int -> i < j }
            } else {
                return genMatrix { i: Int, j: Int -> i <= j }
            }
        }
    }

    fun fixPosition(position: Int) {
        var pos = position + lst
        tree[pos] = getMatrix(position)
        while (pos > 1) {
            pos /= 2
            tree[pos] = tree[2 * pos] * tree[2 * pos + 1]
        }
    }

    for (i in 0 until n - 1) {
        fixPosition(i)
    }

    repeat(q) {
        val p = readInt() - 1
        current[p] = 1 - current[p]
        fixPosition(p)
        if (p != 0) fixPosition(p - 1)
        println(tree[1].x.flatMap { it.map {it.toLong()} }.sum() % MOD)
    }


}

private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readLongs() = readStrings().map { it.toLong() }
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }