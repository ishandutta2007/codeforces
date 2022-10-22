private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    val a = readInt()
    for (i in 0 until a){
        val x = readInt()
        if (x < 4) {println(-1)}
        else if (x == 4) println("2 4 1 3")
        else{
            var j = x
            while (j > 0) {
                print("$j ")
                j -= 2
            }
            j += 5
            print("$j ")
            j -= 2
            if (x % 2 == 0) print("1 ")
            print("$j ")
            j += 4
            while (j <= x){
                print("$j ")
                j += 2
            }
            println()
        }
    }

}