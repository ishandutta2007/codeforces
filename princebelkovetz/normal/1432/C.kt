fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val n = readLine()!!.toInt();
        var sum = 0;
        var items: List<Int> = readLine()!!.split(" ")!!.map{it.toInt()};
        for (x in items)
            sum += x
        println((sum + n - 1) / n);
    }

}