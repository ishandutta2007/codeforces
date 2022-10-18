private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val a = readInts()

    for (i in 0 until n) {
        for (j in 0 until n) {
            if (a[i] >= a[j]) continue
            for (k in 0 until n) {
                if (a[j] >= a[k]) continue
                val res = arrayOf(i+1,j+1,k+1)
                println(res.map { it.toString() }.joinToString(" "))
                return
            }
        }
    }
    println("-1 -1 -1")
}