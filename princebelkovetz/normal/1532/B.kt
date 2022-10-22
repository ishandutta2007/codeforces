
fun main(){
    var tt = readLine()!!.toInt()
    while (tt-->0){
        val (a, b, x) = readLine()!!.split(" ").map{ it.toLong() }
        println((x + 1) / 2 * a - x / 2 * b)
    }
}