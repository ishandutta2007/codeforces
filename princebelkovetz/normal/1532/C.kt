
fun main(){
    var tt = readLine()!!.toInt()
    while (tt-->0){
        val (n, k) = readLine()!!.split(" ").map { it.toInt() }
        for (i in 0 until n){
            print('a' + (i % k))
        }
        println()
    }
}