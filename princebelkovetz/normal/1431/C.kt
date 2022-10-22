fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val (n, k) = readLine()!!.split(" ").map{ it.toInt() }
        val a: List<Int> = readLine()!!.split(" ").map{ it.toInt() }
        var ans = 0;
        for (i in 0 until n){
            var res = 0;
            for (j in i until (n - i) / k + i){
                res += a[j];
            }
            if (res > ans)
                ans = res;
        }
        println(ans);
    }

}