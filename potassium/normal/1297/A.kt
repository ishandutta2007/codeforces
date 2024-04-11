import java.util.*
 
fun main() {
     val t = readLine()!!.toInt();
     
     for (i in 0 until t) {
         var n = readLine()!!.toInt();
         if (n < 1000) {
             println("${n}");
             continue;
         }
         
         if (n < 999500) {
             val d1 = n % 1000;
             n /= 1000;
             
             if (d1 >= 500)
                n++;
                
             println("${n}K");
             continue;
         }
         
         val d2 = n % 1000000;
         n /= 1000000;
         
         if (d2 >= 500000)
            n++;
         
         println("${n}M");
     }
}