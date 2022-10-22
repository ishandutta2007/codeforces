private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    val t = readInt()
    for (i in 1..t){
        val (a,b)=readInts()
        println(60*24-a*60-b)
    }

}