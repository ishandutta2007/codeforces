import java.util.*


fun main(){
    val sc = Scanner(System.`in`);
    val n = sc.nextInt();
    var k = sc.nextInt();
    var a = Array(n){0}
    for(i in 0 until n){
        a[i] = sc.nextInt();
    }
    a.sort();var res = 0;
    if(k == 0) res = 1;
    else if(k == n) res = 1000000000
    else res = a[k-1];
    var cnt = 0;
    for(i in 0 until n){
        if(a[i] <= res) ++cnt;
    }
    if(cnt != k) println(-1);
    else println(res);
}