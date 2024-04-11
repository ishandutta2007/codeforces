import java.lang.Long.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun cost(a: LongArray): Long {
    val n = a.size

    if (n == 1) {
        return 0L
    }

    var res = Long.MAX_VALUE
    var sl = 0L
    var sr = 0L
    var ssl = 0L
    var ssr = 0L

    for (i in 0 until n) {
        if (i > 0) sr += a[i]
        ssr += i*a[i]
    }

    for (i in 0 until n-1) {
        res = min(res, ssl + ssr)

        sl += a[i]
        ssl += sl

        ssr -= sr
        sr -= a[i+1]

        res = min(res, ssl + ssr)
    }

    return res
}

fun main() {
    val (m, n, q) = readInts()

    var a = Array<LongArray>(m) { LongArray(n) }
    var b = LongArray(m)
    var c = LongArray(n)

    for (i in 0 until m) {
        val row = readInts()
        for (j in 0 until n) {
            a[i][j] = 0L + row[j]
            b[i] += a[i][j]
            c[j] += a[i][j]
        }
    }

    print(cost(b) + cost(c))

    repeat(q) {
        val (i,j,x) = readInts()
        val diff = x-a[i-1][j-1]
        a[i-1][j-1] += diff
        b[i-1] += diff
        c[j-1] += diff
        print(" ")
        print(cost(b) + cost(c))
    }
    println()
}