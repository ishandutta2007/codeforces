import java.util.*

fun main(){
    var sc = Scanner(System.`in`);
    var n = sc.nextInt();
    var a = IntArray(n);
    for(i in 0 until n){
        a[i] = sc.nextInt();
    }
    var mx : Long = -1;
    var ps : Long = -1;
    for(i in 0 until n){
        if(a[i] >= mx){
            mx = a[i].toLong();
            ps = (i+1).toLong();
        }
    }
    var ans : Long = ps+(mx-1)*n;
    println(ans);
}