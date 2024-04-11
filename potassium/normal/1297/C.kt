import java.util.*
 
fun main() {
    val t = readLine()!!.toInt();
    
    for (i in 0 until t) {
        val n = readLine()!!.toInt();
        
        var ans =  StringBuilder();
        for (j in 0 until n)
            ans.append('0');
            
        var a = readLine()!!.split(" ").map { it.toInt() }
        
        var sum = 0;
        var minv = 2147483647;
        var minl = -1;
        
        for (j in 0 until n) {
            if (a[j] > 0) {
                ans[j] = '1';
                sum += a[j];
                if (a[j] < minv) {
                    minv = a[j];
                    minl = j;
                }
            }
            
            if (a[j] < 0) {
                if (-a[j] < minv) {
                    minv = -a[j];
                    minl = j;
                }
            }
        }
        
        sum -= minv;
        if (ans[minl] == '1')
            ans[minl] = '0';
        else
            ans[minl] = '1';
            
        println(sum);
        println(ans.toString());
    }
}