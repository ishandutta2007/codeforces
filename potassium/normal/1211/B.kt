import java.util.*

fun main() {
     val n = readLine()!!.toLong();
     val x = readLine()!!.split(" ").map { it.toLong() };
     
     var ans = 0L;
     for (i in 0 until n) {
          var newval = ((x[i.toInt()]-1)*n + i + 1).toLong();
          if (newval > ans) ans = newval;
     }
     
     println(ans);
}