
fun main(){
    var tt = readLine()!!.toInt()
    while (tt-->0){
        var (a, b) = readLine()!!.split(" ").map{ it.toInt() }
        println(a + b)
    }
}