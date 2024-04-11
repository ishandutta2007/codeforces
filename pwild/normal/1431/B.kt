private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val a = readLn()
        val w = a.filter { it == 'w' }.length
        val v = a.split('w').map { it.length/2 }.sum()
        println(v+w)
    }
}