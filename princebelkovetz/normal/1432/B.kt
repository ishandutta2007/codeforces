fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val n = readLine()!!.toInt();
        val x = n / 2 + 1;
        println(n - x)
    }

}