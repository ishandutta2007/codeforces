private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val tc = readInt()
    repeat(tc) {
        val num = readLn()
        val res = ArrayList<String>()
        for (i in num.indices) {
            if (num[i] != '0') {
                res.add(num[i] + "00000000000000000000000".substring(0,num.length-i-1))
            }
        }
        println(res.size)
        println(res.map { it.toString() }.joinToString(" "))
    }
}