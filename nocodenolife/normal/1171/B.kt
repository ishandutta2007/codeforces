fun main(){
    val (y, b, r) = readLine()!!.split(" ").map { it.toInt() }
    
    var m = minOf(y, b - 1, r - 2)
    var x = (m+1)*3
    
    println(x)
}