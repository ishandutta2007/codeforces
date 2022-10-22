private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    val a = readInt()
    for (i in 0 until a){
        val (x, y) = readInts()
        println(x + y)
    }

}