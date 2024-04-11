private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>){
    val (a,b,c,d) = readInts()
    val arr: Array<Int> = arrayOf(a,b,c,d)
    var ch = -1
    var ff: Int = 0
    for (i in 0 .. arr.size-1 step 1){
        if (ch<arr[i]){
            ch=arr[i]
            ff=i
        }
    }
    for (i in 0..arr.size-1){
        if (i!=ff){
            val y = arr[ff]-arr[i]
            print("$y ")
        }
    }


}