private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    var a = readInt()
    while (a != 0){
        var item: Int = readInt()
        val answer = mutableListOf<Int>()
        var temp = 1
        while (item > 0){
            if (item % 10 > 0){
                answer += item % 10 * temp
            }
            temp *= 10
            item /= 10
        }
        println(answer.size)
        for (elem in answer){
            print("$elem ")
        }
        println()
        a--
    }

}