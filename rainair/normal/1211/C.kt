import java.util.*

class Ice(var l:Long,var r:Long,var c:Long);

fun main(){
    var sc = Scanner(System.`in`);
    var n = sc.nextInt();
    var k = sc.nextLong();
    var a = mutableListOf<Ice>();
    for(i in 0 until n){
        var x = sc.nextInt();
        var y = sc.nextInt();
        var z = sc.nextInt();
        a.add(Ice(x.toLong(),y.toLong(),z.toLong()));
    }
    a.sortBy{it.c};
    var ans:Long = 0;
    for(e in a){
        k = k-e.l;
        ans = ans+(e.c*e.l).toLong();
    }
    if(k < 0){
        println(-1);
        return;
    }
    for(e in a){
        var rem:Long = e.r-e.l;
        if(rem < k){
            k -= rem;
            ans += (rem*e.c).toLong();
        }
        else{
            ans += (k*e.c).toLong();
            println(ans);
            return;
        }
    }
    println(-1);
}