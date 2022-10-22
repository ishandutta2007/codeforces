private fun readLn() = readLine()!!
private fun readInt() = readLn().toInt()
private fun readStrings() = readLn().split(" ")
private fun readInts() = readStrings().map { it.toInt() }

fun main(args:Array<String>) {
    val (a, b) = readInts()
    val ls: List<Int> = readInts()
    var mn = ls[0]
    var mx = ls[0]
    var now = ls[0]
    var cou = 0
    for (i in 1..a-1) {
        now += ls[i]
        if (now < mn) {
            mn = now
        }
        if (now > mx) {
            mx = now
        }
    }
    if ((mn<=0) and (mx>=0)){
        mx-=mn
    } else if ((mx<0) and (mn<0)){
        mx=-mn
    }
    if (b+1-mx>0){
        println(b+1-mx)
    } else{
        println(0)
    }

}