import java.util.*

fun main() {
     val n = readLine()!!.toInt();
     val r = readLine()!!.split(" ").map { it.toInt() }
     
     var ans = Array<Pair<Int,Int>>(3) { Pair<Int,Int>(0,0) };
     ans[0] = Pair<Int,Int>(r[0],0);
     var ansptr = 0;
     
     for (i in 1 until n) {
          if (r[i] == ans[0].first) continue;
          if (r[i] == ans[ansptr].first) continue;
          
          ansptr++;
          ans[ansptr] = Pair<Int,Int>(r[i],i);
          if (ansptr == 2) break;
     }
     
     if (ansptr < 2) {
          println("-1 -1 -1");
     } else {
          ans.sortBy( {it.first} );
          var loc = Array<Int>(3) { 0 };
          loc[0] = ans[0].second;
          loc[1] = ans[1].second;
          loc[2] = ans[2].second;
          print(loc[0]+1);
          print(" ");
          print(loc[1]+1);
          print(" ");
          print(loc[2]+1);
     }
}