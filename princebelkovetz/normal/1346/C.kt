private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toLong() }

fun main(args:Array<String>) {
    var a = readInt()
    while (a != 0){
        val (n, k, x, y) = readInts()
        val array = readInts().sorted().reversed()
        var ans1: Long = 0
        var ans2: Long = y
        var s: Long = array.sum()
        for (elem in array){
            if (elem > k){
                ans1 += x
            }
            if (s > k * n) {
                s -= elem
                ans2 += x
            }
        }
        if (ans2 < ans1) {println(ans2)}
        else{println(ans1)}

        a--
    }

}