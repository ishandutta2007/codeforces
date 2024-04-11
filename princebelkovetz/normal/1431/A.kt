fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val n = readLine()!!.toInt();
        var a: List<Long> = readLine()!!.split(" ").map{ it.toLong() }
        var ans: Long = 0;
        for (i in 0 until n){
            var cur = 0;
            for (j in 0 until n){
                if (a[j] >= a[i])
                    cur++;
            }
            if (cur * a[i] >= ans)
                ans = cur * a[i];
        }
        System.out.println(ans);
    }

}