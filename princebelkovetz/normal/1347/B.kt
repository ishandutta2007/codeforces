private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    val a = readInt()
    for (i in 0 until a){
        val (x1, y1) = readInts()
        val (x2, y2) = readInts()
        val array = intArrayOf (x1, y1, x2, y2)
        array.sort()
        if ((array[3] == array[2]) and (array[0] + array[1] == array[2]) and (x1 != y1) and (y2 != x2)){
            print("yeS\n")
        } else {print("nO\n")}
    }

}