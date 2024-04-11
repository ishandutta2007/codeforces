private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    var n = readInt()
    var arr = readInts()
    var largest = 0
    var slargest = 0
    var ans = 0
    for (i in 0 until n) {
        if (slargest > arr[i]) {
            ans++
        } else {
            slargest = arr[i]
            if (slargest > largest) {
                var tmp = largest
                largest = slargest
                slargest = tmp
            }
        }
    }
    println(ans)
}