import java.util.*
 
fun main() {
    val t = readLine()!!.toInt();
    
    for (i in 0 until t) {
        var (n,k) = readLine()!!.split(" ").map { it.toInt() }
        var a = readLine()!!.split(" ").map { it.toInt() }
        
        var b = Array<Pair<Int, Int>>(n) {Pair<Int, Int>(0, 0)};
        for (j in 0 until n)
            b[j] = Pair<Int,Int>(a[j], j);
        b.sortBy { it.first };
        
        var ans = Array<Int>(n) {0};
        
        for (j in n-2 downTo 0) {
            val target = b[n-1].first - (n-1-j);
            var diff = target - b[j].first;
            
            if (k < diff)
                diff = k;
                
            k -= diff;
            ans[b[j].second] += diff;
            
            if (k == 0)
                break;
        }
        
        val avg = k / n;
        var rem = k % n;
        
        for (j in n-1 downTo 0) {
            ans[b[j].second] += avg;
            if (rem > 0) {
                ans[b[j].second]++;
                rem--;
            }
        }
        
        for (j in 0 until n)
            print("${ans[j]} ");
        println();
    }
}