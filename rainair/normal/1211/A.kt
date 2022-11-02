import java.util.*

class P(val v:Int,val idx:Int);

fun main(){
    var sc = Scanner(System.`in`);
    var n = sc.nextInt();
    val S = hashMapOf<Int,Int>()
    var a = mutableListOf<P>();
    for(i in 0 until n){
        val r = sc.nextInt();
        S[r] = i+1;
    }
    if(S.size < 3){
        println("-1 -1 -1");
        return;
    }
    var cnt = 0;
    for(e in S){
      //  print("${e.value} ");
        a.add(P(e.key,e.value));
    }
    a.sortBy{it.v};
    println("${a[0].idx} ${a[1].idx} ${a[2].idx}");
}