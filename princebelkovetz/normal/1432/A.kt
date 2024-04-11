fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val (a, b) = readLine()!!.split(" ").map { it.toInt() }
        println(a + b)
    }

}