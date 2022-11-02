import java.util.*

class P(val cap:Int,val ind:Int)

fun main(){
    val sc = Scanner(System.`in`)
    val n = sc.nextInt();
    var c = IntArray(n);
    var p = IntArray(n);
    for(i in 0 until n){
        c[i] = sc.nextInt();
        p[i] = sc.nextInt();
    }
    val k = sc.nextInt();
    val tables = mutableListOf<P>();
    for(i in 0 until k){
        val r = sc.nextInt();
        tables.add(P(r,i));
    }
    tables.sortBy{it.cap};
    val vis = BooleanArray(n);
    var res = 0;
    val res1 = mutableListOf<Int>();
    val res2 = mutableListOf<Int>();
    for(i in 0 until k){
        var mx = 0;
        var ps = -1;
        for(j in 0 until n){
            if(vis[j]) continue;
            if(c[j] <= tables[i].cap && mx < p[j]){
                mx = p[j];
                ps = j;
            }
        }
        if(ps != -1){
            res1.add(ps+1);
            res2.add(tables[i].ind+1);
            res += mx;
            vis[ps] = true;
        }
    }
    println("${res1.size} $res");
    for(i in 0 until res1.size){
        println("${res1[i]} ${res2[i]}");
    }
}