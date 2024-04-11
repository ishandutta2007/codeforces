
private fun solve(test: Int) {
    val n = readInt()
    val a = readInts().toIntArray()
    val s = readLn()
    fun check(z: IntArray): Boolean {
        for (i in 1 until n) {
            z[i] += z[i - 1]
        }
        for (i in 0 until n) {
            if (z[i] > i + 1) {
                return false
            }
        }
        return true
    }
    val blues = IntArray(n)
    val reds = IntArray(n)
    for ((i, c) in s.withIndex()) {
        if (c == 'B') {
            if (a[i] < 1) {
                println("No")
                return
            }
            if (a[i] > n) {
                blues[n - 1]++
            } else {
                blues[a[i] - 1]++
            }
        } else {
            if (a[i] > n) {
                println("No")
                return
            }
            if (a[i] < 1) {
                reds[n - 1]++
            } else {
                reds[n - a[i]]++
            }
        }
    }
    if (!check(blues) || !check(reds)) {
        println("No")
    } else {
        println("Yes")
    }
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