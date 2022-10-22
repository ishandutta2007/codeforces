/**
 * You can edit, run, and share this code. 
 * play.kotlinlang.org 
 */

val MAX = 1001
fun main() {
    var t = readLine()!!.toInt()
    while(t-- > 0){
        val arr = readLine()!!.split(" ").map { it.toInt() }
        var n = arr[0]
        var k = arr[1]
        var str = readLine()!!
        var cnt = 0
        for(i in str.indices){
            if (str[i]=='(') cnt++
            else cnt--
            if (cnt == 0) k++
        }
        if (k>n/2) k = n/2
        println("${k}")
        
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