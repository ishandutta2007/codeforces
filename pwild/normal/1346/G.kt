import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun gcd(a: Int, b: Int): Int {
    if (b == 0) return a
    return gcd(b, a%b)
}

fun solve(a: List<Int>, p: List<Int>): List<Int> {
    val n = a.size

    if (n == 2) return listOf(a[0],p[0],a[1],p[0])

    for (i0 in 0 until 3) {
        for (i1 in i0+1 until 3) {
            var candidates = mutableSetOf<Int>()
            for (len in p) {
                if ((a[i1]-a[i0])%len == 0) {
                    var ok = true
                    for (x in candidates) if (len%x == 0) ok = false
                    if (ok) candidates.add(len)
                }
            }
            // for (x in candidates) println(x)

            for (len in candidates) {
                val others = a.filter { it < a[i0] || (it-a[i0])%len > 0 }
                if (others.isEmpty()) {
                    return listOf(a[i0],len,a[i0],len)
                }
                if (others.size == 1) {
                    return listOf(a[i0],len,others[0],len)
                }

                var len2 = others[1]-others[0]
                for (i in 1 until others.size-1) {
                    len2 = gcd(len2, others[i+1]-others[i])
                }
                for (x in p) if (len2%x == 0) {
                    return listOf(a[i0],len,others[0],x)
                }
            }
        }
    }
    return listOf(-1)
}

fun main() {
    readInts()
    val periods = readInts()
    val a = readInts()

    val res = solve(a, periods)
    if (res[0] < 0) {
        println("NO")
    } else {
        println("YES")
        println(res.map { it.toString() }.joinToString(" "))
    }
}