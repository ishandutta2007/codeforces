fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val n = readLine()!!.toInt();
        val a: List<Int> = readLine()!!.split(" ").map{ it.toInt() }
        val b = BooleanArray(n);
        var cur = 0;
        while (true){
            var ind = -1;
            for (i in 0 until n){
                if (!b[i] && (ind == -1 || a[ind] > a[i])){
                    ind = i;
                }
            }
            if (ind == -1) break;
            if (cur >= a[ind]){
                cur = 1;
                print("${ind + 1} ");
                b[ind] = true;
                continue;
            }
            ind = -1;
            for (i in 0 until n){
                if (!b[i] && (ind == -1 || a[ind] < a[i])){
                    ind = i;
                }
            }
            b[ind] = true;
            print("${ind + 1} ");
            cur++;
        }
        println()
    }

}