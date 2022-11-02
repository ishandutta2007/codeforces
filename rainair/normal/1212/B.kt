import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    val n = sc.nextInt();
    val str = sc.next();
    val m = hashMapOf<String,Int>()
    for(i in 0 until n-1){
        val x = str.substring(i,i+2)
        m[x] = m.getOrDefault(x,0)+1;
    }
    var cnt = 0;
    var res: String?=null;
    for(e in m){
        if(cnt < e.value){
            cnt = e.value;
            res = e.key;
        }
    }
    println(res)
}