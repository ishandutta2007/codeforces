private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>){
    val n: Int = readInt()
    val a: List<Int> = readInts()
    var b: List<Int> = listOf(-1)
    for(i in 1..a.size step 1){
        if (!(a[a.size-i] in b)){
            b+=a[a.size-i]
        }
    }
    println(b.size-1)
    for (i in 1..b.size-1){
        val x = b[b.size-i]
        print("$x ")
    }

}