private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readLong() = readLn().toLong() // single long
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints
private fun readLongs() = readStrings().map { it.toLong() } // list of longs

fun main() {
    var n = readInt()
    var arr = readLongs().sortedWith(compareBy({
        var ret = 0
        var tmp = it
        while (tmp % 2 == 0.toLong()) {
            tmp /= 2
            ret++
        }
        ret
    },
            {
                var ret = 0
                var tmp = it
                while (tmp % 3 == 0.toLong()) {
                    tmp /= 3
                    ret++
                }
                -ret
            }));
    println(arr.joinToString(separator = " "))
}