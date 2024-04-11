fun main(){
    val testcases = readLine()!!.toInt();
    for (i in 1..testcases) {
        val s: String = readLine()!!;
        val n = s.length;
        var ans = 0;
        var c: Boolean = false;
        for (i in 0 until n){
            if (i > 0 && s[i] == 'v' && s[i - 1] == 'v' && !c){
                ans++;
                c = true;
            }
            else {
                if (s[i] == 'w') ans++;
                c = false;
            }
        }
        println(ans);
    }

}