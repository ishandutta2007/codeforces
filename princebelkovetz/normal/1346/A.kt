private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    var a = readInt()
    while (a != 0){
        val (n, k) = readInts()
        val z = n / (1 + k + k * k + k * k * k)
        print("$z ${z * k} ${z*k*k} ${z*k*k*k}")
        println()
        a--
    }

}