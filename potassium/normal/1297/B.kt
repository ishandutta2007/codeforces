import java.util.*
 
fun main() {
    val t = readLine()!!.toInt();
    
    for (i in 0 until t) {
        val n = readLine()!!.toInt();
        
        var l = Array<Int>(n) {0};
        var r = Array<Int>(n) {0};
        
        for (j in 0 until n) {
            val x = readLine()!!.split(" ").map { it.toInt() }
            l[j] = x[0];
            r[j] = x[1];
        }
        
        var ans = -1;
        
        for (j in 0 until n) {
            for (k in l[j]-1 until l[j]+2) {
                var total = 0;
                for (x in 0 until n)
                    if (l[x] <= k && k <= r[x])
                        total++;
                        
                if (total == 1)
                    ans = k;
            }
            
            for (k in r[j]-1 until r[j]+2) {
                var total = 0;
                for (x in 0 until n)
                    if (l[x] <= k && k <= r[x])
                        total++;
                        
                if (total == 1)
                    ans = k;
            }
        }
        
        println(ans);
    }
}