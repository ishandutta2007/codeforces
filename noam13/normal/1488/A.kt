/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */

val MAX = 1001
fun main() {
    var t = readLine()!!.toInt()
    while(t-- > 0){
        val arr = readLine()!!.split(" ").map { it.toInt() }
        var x = arr[0]
        var y = arr[1]
        var ans = y%x
        y = y/x
        while(y>0){
            ans+=y%10
            y /= 10
        }
        println("${ans}")
        
    }
    
    /*val arr = readLine()!!.split(" ").map { it.toInt() }
    val can = IntArray(MAX)
    var lst: List<Int> = ArrayList()
    for (i in n-1 downTo 0){
        if (can[arr[i]]==0){
            can[arr[i]] = 1
            lst += arr[i]
        }
    }
    lst = lst.reversed()
    println(lst.joinToString(" "))*/
}