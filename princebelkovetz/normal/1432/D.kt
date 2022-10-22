fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val (n, a, b) = readLine()!!.split(" ").map{it.toInt()};
        var s: String = "";
        for (i in 0..n - 1){
            s += 'a' + i % b;
        }
        println(s);
    }

}