import java.util.*

fun main(){
    val sc = Scanner(System.`in`)
    var n = sc.nextInt()
    val k = sc.nextInt()
    for(i in 0 until k){
        if(n % 10 != 0){
            --n;
        }
        else{
            n /= 10;
        }
    }
    println(n)
}